from sklearn.ensemble import RandomForestClassifier
from test_clang import *
import os
from sklearn.metrics import classification_report
import joblib
from sklearn.tree import export_text
from transformers import AutoModelForSequenceClassification,AutoTokenizer
import torch
from torch.utils.data import DataLoader, Dataset
import os
from torch.nn.functional import sigmoid

device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')
tokenizer = AutoTokenizer.from_pretrained("/home/stu_ug/Documents/CodeBERT/CodeBERT/data/code2nl/cpp_model5/checkpoint-last")
model = AutoModelForSequenceClassification.from_pretrained("/home/stu_ug/Documents/gptsniffer/results/checkpoint-8000", use_safetensors=True)

model.eval()

def content_model_value(filename,path):
    f = open(os.path.join(path,filename),"r")
    code = f.read()
    f.close()
    inputs = tokenizer.encode_plus(code, padding='max_length', max_length=512, truncation=True)
    input_ids = torch.tensor(inputs['input_ids'], dtype=torch.long).to(device).unsqueeze(0)
    attention_mask =  torch.tensor(inputs['attention_mask'], dtype=torch.long).to(device).unsqueeze(0)
   # print(input_ids,attention_mask)
    outputs = model(input_ids, attention_mask=attention_mask)
    logits = outputs.logits
    ss = sigmoid(logits[:, 1])
   # print(ss.tolist()[0])
    return ss.tolist()[0]
#np.set_printoptions(precision=8, suppress=True)
forest_model = RandomForestClassifier(random_state=0)

train_dirPath = "/home/stu_ug/Documents/dataset/gptsniffer_test_data/allpro_train"
test_dirPath = "/home/stu_ug/Documents/dataset/gptsniffer_test_data/allpro_test"
train_label = []
test_label = []

#filename,label,style_guideline,cycle,duplicate,indentation
file = open(os.getcwd()+"/train_result.csv",'r',encoding="big5")
reader = csv.reader(file)
train_feature = list(reader)[1:]
for i in range(len(train_feature)):
    print(i)
    value = content_model_value(train_feature[i][0],train_dirPath)
    train_label.append(train_feature[i][1]) 
    train_feature[i] = [value,train_feature[i][2],train_feature[i][5]]
    
file = open(os.getcwd()+"/test_result.csv",'r',encoding="big5")
reader = csv.reader(file)
test_feature = list(reader)[1:]
for i in range(len(test_feature)):
    print(i)
    value = content_model_value(test_feature[i][0],test_dirPath)
    test_label.append(test_feature[i][1])
    test_feature[i] = [value,test_feature[i][2],test_feature[i][5]]
    
forest_model.fit(train_feature,train_label)
joblib.dump(forest_model, "./2style_content_model.joblib")
score = forest_model.score(test_feature,test_label)
predict_label = forest_model.predict(test_feature)
print(score)
report = classification_report(test_label,predict_label)
print(report)
feature_importances = forest_model.feature_importances_
print(feature_importances)
print(len(forest_model.estimators_))
tree_rules = export_text(forest_model.estimators_[0], feature_names=["content","guideline","indentation"])
print(tree_rules)
#joblib.dump(model, "./style_model.joblib")

