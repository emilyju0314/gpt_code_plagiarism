TEST_P(SequenceManagerTest, DoesNotRecordQueueTimeIfSettingFalse) {
  auto queue = CreateTaskQueue();

  QueueTimeTaskObserver observer;
  sequence_manager()->AddTaskObserver(&observer);

  // We do not record task queue time when the setting is false.
  sequence_manager()->SetAddQueueTimeToTasks(false);
  AdvanceMockTickClock(TimeDelta::FromMilliseconds(99));
  queue->task_runner()->PostTask(FROM_HERE, BindOnce(&NopTask));
  RunLoop().RunUntilIdle();
  EXPECT_THAT(observer.queue_times(), ElementsAre(TimeTicks()));

  sequence_manager()->RemoveTaskObserver(&observer);
}