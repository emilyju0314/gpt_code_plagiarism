所有用來測試的程式。

### code_content_classifier

由github上的公開資料集[code_contests](https://github.com/google-deepmind/code_contests)得到**人寫的程式碼**與**題目**。
將題目的集合整理成**code_content_txt.zip**，用於生成gptsniffer所需的ai code題目，資料夾內包含train、test等的資料。

### codeBert_fine_tunning

利用hungging face上專門給語言模型訓練用的公開資料集[xlcost-text-to-code](https://huggingface.co/datasets/codeparrot/xlcost-text-to-code)，將資料集運用於CodeBert的C++語言訓練。
