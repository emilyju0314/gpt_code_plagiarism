from find_style_feature import *
import joblib
from transformers import AutoModelForSequenceClassification,AutoTokenizer
import torch
from torch.utils.data import DataLoader, Dataset
import os
from torch.nn.functional import sigmoid
from sklearn.metrics import classification_report
forest_model = joblib.load("/home/stu_ug/Documents/our_model/2style_content_model.joblib")

device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')
tokenizer = AutoTokenizer.from_pretrained("/home/stu_ug/Documents/CodeBERT/CodeBERT/data/code2nl/cpp_model5/checkpoint-last")
model = AutoModelForSequenceClassification.from_pretrained("/home/stu_ug/Documents/gptsniffer/results/checkpoint-8000", use_safetensors=True).to(device)

model.eval()
test_data = []
label = []
file_list = []
#dataset_path = "/home/stu_ug/Documents/dataset/gptsniffer_test_data/thevault_test"
dataset_path = "/home/stu_ug/Documents/test"
for file in os.listdir(dataset_path):
    print("1")
    file_list.append(file)
    file_path = os.path.join(dataset_path,file)
    f = open(file_path,"r",errors="ignore")
    code = f.read()
    f.close()
    inputs = tokenizer.encode_plus(code, padding='max_length', max_length=512, truncation=True)
    input_ids = torch.tensor(inputs['input_ids'], dtype=torch.long).to(device).unsqueeze(0)
    attention_mask =  torch.tensor(inputs['attention_mask'], dtype=torch.long).to(device).unsqueeze(0)
    
    outputs = model(input_ids, attention_mask=attention_mask)
    logits = outputs.logits
    ss = sigmoid(logits[:, 1]).tolist()[0]
    data = [ss,style_guideline(file_path),find_inden(file_path)]
    test_data.append(data)
    label.append(file.split("_")[0])
    
predict = forest_model.predict(test_data)
for i in range(len(predict)):
    print(file_list[i])
    if predict[i]=='0':
        print("written by chatGPT!!!!")
    else:
        print("written by human.")
#print(predict)
#report = classification_report(label,predict)
#print(report)
#score = forest_model.score(test_data,label)
#print(score)
