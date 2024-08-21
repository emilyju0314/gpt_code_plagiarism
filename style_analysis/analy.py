import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import seaborn as sns
from collections import defaultdict

file = pd.read_excel("result.xlsx")
file.drop(file.filter(regex="Unname"),axis=1, inplace=True)
file.drop(file.filter(regex="ai_error"),axis=1, inplace=True)
file2 = pd.read_excel("group.xlsx")
program, DS, algo = list(file2['program']), list(file2['DS']), list(file2['algo'])
ac = list(file2['AC'])

def guideline_analy():
    guideline_peo, guideline_ai = [], []

    for i in range(file['guideline'].index.stop):
        guideline_ai.append(file['guideline'][i])
        guideline_peo.append(file['guideline.1'][i])

    plt.xlim(0,0.3)
    plt.ylabel("count")
    plt.title("style guideline")
    sns.distplot(guideline_ai,kde=True,bins='auto',label="ai")
    sns.distplot(guideline_peo,kde=True,bins='auto',label="people")
    plt.legend()
   # plt.savefig("guideline.png")
    plt.show()

    plt.ylim(-0.0005,0.2)
    plt.xlabel("people")
    plt.ylabel("ai")
    plt.title("( people,ai ) pair")
    plt.scatter(guideline_peo,guideline_ai)
 #   plt.plot([0, 0.2], [0, 0.2], color="red")
    plt.savefig("guide_scatter.png")
    plt.show()
    #df = pd.DataFrame([guideline_ai,guideline_peo]).transpose()
    #print(df.corr())
def inden_analy():
    inden_peo, inden_ai = [], []
    for i in range(file['test_inden'].index.stop):
        inden_ai.append(file['test_inden'][i])
        inden_peo.append(file['test_inden.1'][i])

    plt.ylabel("count")
    plt.title("indentation")
    sns.distplot(inden_ai,kde=False,bins='auto',label="ai")
    ax = sns.distplot(inden_peo,kde=False,bins='auto', label="people")
    plt.legend()
    s = 0
    for p in ax.patches:
        print(p)
        s += p.get_height()

    for p in ax.patches:
        if int(p.get_height()) == 0:
            continue
        if p.get_facecolor() == (0.12156862745098039, 0.4666666666666667, 0.7058823529411765, 0.4):
            color = "blue"
        else:
            color = "orange"
        ax.text(p.get_x() + p.get_width() / 2.,
                p.get_height(),
                '{}'.format(int(p.get_height())),
                fontsize=14, color=color, ha='center', va='bottom')

    plt.savefig("indentation.png")
    plt.show()
def cycle_analy():
    cycle_peo, cycle_ai = [], []
    for i in range(file['cycle'].index.stop):
        if file['ai_file'][i] in ac:
            cycle_ai.append(file['cycle'][i])
            cycle_peo.append(file['cycle.1'][i])
    df = pd.DataFrame([cycle_ai,cycle_peo]).transpose()
    print(df.corr())
   # plt.ylim(0,20)
    plt.xlabel("people")
    plt.ylabel("ai")
    plt.title("cycle ( people,AC_ai ) pair")
    sns.regplot(x=cycle_peo,y=cycle_ai)
    plt.legend()
    plt.savefig("cycle.png")
    plt.show()

def repeat_analy():
    cycle_peo, cycle_ai = [], []
    for i in range(file['repeat'].index.stop):
        if file['ai_file'][i] in ac:
            cycle_ai.append(file['repeat'][i])
            cycle_peo.append(file['repeat.1'][i])
    df = pd.DataFrame([cycle_ai, cycle_peo]).transpose()
    print(df.corr())
    # plt.ylim(0,20)
    sns.regplot(x=cycle_peo, y=cycle_ai)
    plt.legend()
    plt.show()

if __name__ == '__main__':
   # guideline_analy()
    #inden_analy()
    cycle_analy()
    #repeat_analy()