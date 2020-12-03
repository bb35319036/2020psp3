#include <stdio.h>
#include <string.h>
#define DEBUG

#define ALPHABET_LEN    255

char StrOriginal[] = "On a dark deseart highway, cool wind in my hair.";
char StrKey[] = "wind";

char* ForceSearch(char text[], char key[])
{
    int start=0,pos=0;
    int StrOriginal_len=strlen(StrOriginal),StrKey_len=strlen(StrKey);
while(start+pos< StrOriginal_len && pos<StrKey_len)//開始位置と比較位置が文字の長さより小さい場合にループする条件を置く
    {
        if(text[start+pos]==key[pos])//文字が一致した場合の分岐
        {
            pos++;                                        //比較位置をずらす
            
            if(StrKey_len == pos)
            { 
                return &text[start];//文字列すべて一致した場合開始位置から後の文字をreturnする
            }
        
            
        } 
         else
        {
            start++;//文字が一致していない場合開始位置を一つずらす
            pos=0;//比較位置の初期化
        }
         
     }
     return NULL;
} 


   
   
    //  ここを実装する



char* BMSearch(char text[], char key[])
  {  char table[256]  ;
    int i;
    for ( i = 0; i < 256; i++)
    {
        table[i] = strlen(StrKey) ;
    }

    
for (i=0; i<=strlen(StrKey); i++)          
{   
    table[StrKey[i]] = strlen(StrKey) -(i+1) ;  //tableにStrKeyの配列の文字を参照にしずらしテーブルを作成
}

  

    int index=0,key_index=0,index2;
    int StrOriginal_len = strlen(StrOriginal);
    int StrKey_len = strlen(StrKey);

    index = StrKey_len ; //indexを文字列の後ろに設定
    key_index = StrKey_len-1 ;//終端文字から一つ後ろから比較するために-1
   
    
    i=0;
    
    while(index < StrOriginal_len )//indexが文字列より小さい場合ループする条件を置く
    {   
            if(text[index]==key[key_index] ) //textの文字とkey文字を比較し一致している場合if文に入る
            {   
                i++;
               
                    if(i  == StrKey_len)    //次の比較位置へずらす前に比較回数（文字列すべて一致しているか）を参照
                     { 
                        return &text[index]; //その時の一致した場所から後ろの文字を返す
                        break;
                    }
                
                index = index-1;           //比較位置を一つ前へずらす
                key_index = key_index - 1; 
                
            }
            else
            {
                
                     index2 = index +i;  //繰り返した回数分足せば比較開始場所が分かる
                    index = index + table[text[index]];
                   

                if (index <= index2)  //比較開始場所と現在の比較場所を比較し同じか前だと比較開始場所に１足してindexを更新
                {
                    index = index2 +1;
                }
                
    
           
    
            i=0;                                  //ここで文字列すべてが一致してないときのiのカウントが足されないように初期化           

    

            }


    

    }  
    
    return NULL;
    
     //  ここを実装する

}

int main(void)
{
    char*   str;
    str = ForceSearch(StrOriginal, StrKey);
    printf("Force Search. Find keyword at:%s\n", str);

    str = BMSearch(StrOriginal, StrKey);
    printf("BM Search. Find keyword at:%s\n", str);

    return 0;
}