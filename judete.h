
struct judete
{
	char judet[25];
	char municipiu[25];
	char indicatorauto[3];
	char primar[30];
	char regiune[35];
	char pctcardinal[35];
	char obiectiv[35], pozaobiectiv[35];
	char pozajudet[35];
	char harta[35];
	char stema[35];
	//char vecin1[25], vecin2[25], vecin3[25], vecin4[25], vecin5[25], vecin6[25], vecin7[25];
	char vecin[9][45];
	int locuitori, prefix, cod, suprafata, densitate, municipii, orase, comune;
}
j[999];


struct personalitati
{
	char nume[45];
	char nascut[40];
	char decedat[60];
	char varsta[25];
	char casatorit[45];
	char cetatenie[40];
	char ocupatie[9][45];
	char numepoza[35];
}
d[999];


int k=0, d_k=0;
int tries = 3;
void citire();
void motto();
void meniu();
void introducere();
void generalitati1();
void generalitati2();
void bazadedate();
void evolutie();
void parola();
void admin_da();
void admin_nu();
bool admin=false;
void harta();
void judet1(int );
void judet2(int );
void judet3(int );
void tabel1();
void aplicatii();
void aplicatie1();
void aplicatie2();
void aplicatie2_2(int );
void pagina_web();
void pagina_web_2(int );
void pagina_web_3(int );
void quiz();
void structura();
void bibliografie();
void autor();
int edit( int&, char[], int&, bool );
int selectindex();
char* cautare( char*, int& );
void encryptDecrypt(char[]);
void sortjud( bool );