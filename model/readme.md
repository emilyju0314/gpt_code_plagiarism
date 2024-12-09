### find_style_feature.py
實作四個feature : Cyclomatic complexity(圈複雜度)、repetitive patterns(重複程式碼)、code indentation(縮排)、style guidelines consistency(風格一至性)

### train_result.csv、test_result.csv
將code_contests資料集的train及test檔案預先用find_style_feature.py跑好style_feature存取(加快training速度)

### train_model.py
將codeBERT及style feature 訓練成隨機森林model

#### 存檔(存為三個model)
1. 2style_content_model:使用codeBERT的值、code indentation與style guideline訓練的model
2. 3style_content_model:使用codeBERT的值、code indentation、style guideline與cyclomatic complexity訓練的model
3. noMax_3style_content_model:不限制隨機森林大小的3style_content_model

| Train feature | Style guidelines,cycle complexity,indentation(3 style feature) | Style guidelines,indentation(2 style feature) | codeBERT value | codeBERT,2 style feature|
| ---- | ---- | ---- | ---- | ---- |
|Accuracy|60%|68%|73%|76%|

### test_dataset_model.py
使用hugging face的資料集(加上爬蟲程式碼)測試model的性能

### final_model.py
讀取local端資料夾，並且輸出屬於GPT或人類哪個類別
