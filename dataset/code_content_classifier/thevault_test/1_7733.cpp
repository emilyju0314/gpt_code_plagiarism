void LocApiV02 :: reportEngineState (
    const qmiLocEventEngineStateIndMsgT_v02 *engine_state_ptr)
{

  LOC_LOGV("%s:%d]: state = %d\n", __func__, __LINE__,
                 engine_state_ptr->engineState);

  struct MsgUpdateEngineState : public LocMsg {
      LocApiV02* mpLocApiV02;
      bool mEngineOn;
      inline MsgUpdateEngineState(LocApiV02* pLocApiV02, bool engineOn) :
                 LocMsg(), mpLocApiV02(pLocApiV02), mEngineOn(engineOn) {}
      inline virtual void proc() const {

          // Call registerEventMask so that if qmi mask has changed,
          // it will register the new qmi mask to the modem
          mpLocApiV02->mEngineOn = mEngineOn;
          mpLocApiV02->registerEventMask(mpLocApiV02->mMask);

          if (!mEngineOn) {
              for (auto resender : mpLocApiV02->mResenders) {
                  LOC_LOGV("%s:%d]: resend failed command.", __func__, __LINE__);
                  resender();
              }
              mpLocApiV02->mResenders.clear();
          }
      }
  };

  if (eQMI_LOC_ENGINE_STATE_ON_V02 == engine_state_ptr->engineState) {
      sendMsg(new MsgUpdateEngineState(this, true));
  }
  else if (eQMI_LOC_ENGINE_STATE_OFF_V02 == engine_state_ptr->engineState) {
      sendMsg(new MsgUpdateEngineState(this, false));
  }

}