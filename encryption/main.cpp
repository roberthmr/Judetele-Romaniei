#include <iostream>
#include <conio.h>
#include<string.h>


using namespace std;

void encryptDecrypt(char inpString[])
{
    // Define XOR key
    // Any character value will work
    char xorKey = 'P';

    // calculate length of input string
    int len = strlen(inpString);

    // perform XOR operation of key
    // with every caracter in string
    for (int i = 0; i < len; i++)
    {
        inpString[i] = inpString[i] ^ xorKey;
        printf("%c",inpString[i]);
    }
}

int main()
{
    char sampleString[] = "batman";

    // Encrypt the string
    printf("Encrypted String: ");
    cout<<"x";
    encryptDecrypt(sampleString);
    cout<<"x";
    printf("\n");

    // Decrypt the string
    printf("Decrypted String: ");
    encryptDecrypt(sampleString);

    return 0;
}


/*
int main()
{

    START:
        system("CLS");
    char encr[50]=" b s b e v m f d f m n b j u b s f";
    char parola[35];
    char a;
    int i, j, corect=0;
    cout<<"Dati parola: ";
    for(i=0;;)//infinite loop
    {
        a=getch();
        if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))
        {
            parola[i]=a;
            i++;
            cout<<"*";
        }
        if(a=='\b'&&i>=1)
        {
            cout<<"\b \b";
            i--;
        }
        if(a=='\r')
        {
            parola[i]='\0';
            break;
        }
    }
    if(   int(parola[0]) == int(int(encr[1])-1)  && int(parola[1]) == int(int(encr[3])-1) && int(parola[2]) == int(int(encr[5])-1) && strlen(parola)*2==strlen(encr))
    {
        corect=1;
        system("CLS");
        cout<<"\nCorect!";
    }
    if(corect==0)
        goto START;


}
*/
