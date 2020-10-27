# 紀錄高中寫的程式


## 目前有的程式
- [成績系統](#成績系統)

## 規劃在寫的程式
- [隨機座位系統](#隨機座位系統)

---
## 成績系統
### 緣由 : 
2020/10/22，這天，段考成績單出來了，但是是需要簽名確認的那種，所以並沒有寫上總平均和班排，所以我就想說來寫一個程式可以算出排名和平均好了。
然而，我寫完程式後就找不到成績單了:(

[相關圖片](https://i.imgur.com/wc7B2H6.png)
### 程式碼
```cpp=
//修正四捨六入五成雙

#include <bits/stdc++.h> //黑科技 : 萬用函式庫
#define endl '\n'
using namespace std;

//算加權後的平均
double aver(double ch, double en, double ma, double his, double geo, double ear, double phy, double che)
{
    return ((ch + en + ma)*4 + (his + geo + ear)*2 + (phy + che)) / 20;
}

//bubble sort(泡沫排序法)
void bubsort(vector<pair<int, double> >& vec)
{
    for(int i = vec.size()-1; i > 0; i--)
    {
        for(int j = 0; j <= i-1; j++)
        {
            if( vec[j].second < vec[j+1].second)
            {
                pair<int, double> tmp = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = tmp;
            }
        }
    }
}
int main()
{
    vector<pair<int, double> > cla; //宣告一個型態為pair的vector
    int num; //座號
    double ch, en, ma, his, geo, ear, phy, che; //ch國文, en英文, ma數學, his歷史, geo地理, ear地科, phy物理, che化學
    int count = 0;
    ofstream output; //酷酷的東西
    output.open("score.txt"); //開一個名叫score.txt的檔案  
    while((cout << "請依序輸入座號，國文，英文，數學，歷史，地理，地科，物理，化學成績" << endl) && (count < 48 /*班級人數*/))
    {
        cin >> num >> ch >> en >> ma >> his >> geo >> ear >> phy >> che; //輸入 
        double average = round(aver(ch, en, ma, his, geo, ear, phy, che)*100) / 100; //算平均 
        cout << fixed << setprecision(2) << "你的總平均為: " << average << endl;
        count++; //人數+1
        cla.push_back(make_pair(num, average)); //把這個人的成績丟進vector
    }
    bubsort(cla); //排序

    //輸出vector
    for(unsigned int a = 0; a < cla.size(); a++)
    {
        cout << fixed << setprecision(2) << cla[a].first << " " << cla[a].second << endl; //輸出
        output << fixed << setprecision(2) << cla[a].first << " " << cla[a].second << endl; //丟進txt檔
    } 
    
 }
```

> [name=YuYu][time=Tue, October 27, 2020 2:07 PM]

---
## 隨機座位系統
### 緣由 : 
2020/10/23，這天是星期五，上程設班時同學看了我寫的成績系統，我就問她還有什麼可以寫的小程式，她就說他們班最近換位子，她換到一個很爛的位子，所以希望我可以寫一個換座位的程式，然後留個後門給她 :poop:
