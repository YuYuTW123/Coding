//修正四捨六入五成雙
//尚未測試過

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
