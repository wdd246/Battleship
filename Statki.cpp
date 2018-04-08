#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int gop = 0;
int goc = 0;
void plansza(int k, int w,int s1x,int s2x,int s3x,int s4x,int s1y,int s2y,int s3y,int s4y,int c1x,int c1y,int c2x,int c2y,int c3x,int c3y,int c4x,int c4y) {
	bool ptraf = false;
	bool ctraf = false;
	//plansza gracza
	int** p_plansza = new int*[10];
	for(int i=0; i<10; i++) {
		p_plansza[i]=new int[10];
	}
	//plansza komputera
	int** c_plansza = new int*[10];
	for(int i=0; i<10; i++) {
		c_plansza[i]=new int[10];
	}
	srand(time(NULL));
	//int statek[8] = {rand()%10,rand()%10,rand()%10,rand()%10,rand()%10,rand()%10,rand()%10,rand()%10};
	//cout<<sx<<" "<<sy<<endl;
	
	//wypełnianie planszy gracza
	for(int i=0; i<10; i++) {
		for(int j=0; j<10; j++) {
			p_plansza[i][j]=0;
			if((i==s1x && j==s1y)||(i==s2x && j==s2y)||(i==s3x && j==s3y)||(i==s4x && j==s4y)) {
				p_plansza[i][j]=1;
			}
			//cout<<p_plansza[i][j];
		}
		//cout<<endl;
	}
	//wypelnianie planszy komputera
	for(int i=0; i<10; i++) {
		for(int j=0; j<10; j++) {
			c_plansza[i][j]=0;
			if((i==c1x && j==c1y)||(i==c2x && j==c2y)||(i==c3x && j==c3y)||(i==c4x && j==c4y)) {
				c_plansza[i][j]=1;
			}
			//cout<<p_plansza[i][j];
		}
		//cout<<endl;
	}

	//ruch gracza
	cout<<endl;
	cout<<"PLAYER TURN: "<<endl;
	for(int i=0; i<10; i++) {
		for(int j=0; j<10; j++) {
			if((i==k && j==w) && c_plansza[i][j]==1) {
				c_plansza[i][j]=2;
				ptraf = true;
				gop++;
				//cout<<"trafiony"<<endl;

			}
			if((i==k && j==w) && c_plansza[i][j]==0) {
				c_plansza[i][j]=3;
				//cout<<"pudlo"<<endl;

			}
			//cout<<p_plansza[i][j];
		}
		//cout<<endl;
	}

	if(ptraf==false) {
		cout<<"pudlo"<<endl;
	}
	if(ptraf==true) {
		cout<<"Trafiony"<<endl;
	}

	//ruch komputera
	cout<<endl;
	cout<<"NPC TURN: "<<endl;
	int cx = rand()%10;
	int cy = rand()%10;

	for(int i=0; i<10; i++) {
		for(int j=0; j<10; j++) {
			if((i==cx && j==cy) && p_plansza[i][j]==1) {
				p_plansza[i][j]=4;
				ctraf = true;
				goc++;
				//cout<<"trafiony"<<endl;

			}
			if((i==cx && j==cy) && p_plansza[i][j]==0) {
				p_plansza[i][j]=5;
				//cout<<"pudlo"<<endl;

			}
			//cout<<p_plansza[i][j];
		}
		//cout<<endl;
	}

	if(ctraf==false) {
		cout<<"pudlo"<<endl;
	}
	if(ctraf==true) {
		cout<<"trafiony"<<endl;
	}
	if(gop==4) {
		cout<<"Gracz wygral"<<endl;
		exit(0);
	}
	if(goc==4) {
		cout<<"CPU wygral"<<endl;
		exit(0);
	}
}

int main() {
	cout << "Gra w statki" << endl;
	int k;
	int w;
	int s1x,s1y,s2x,s2y,s3x,s3y,s4x,s4y;
	int c1x,c1y,c2x,c2y,c3x,c3y,c4x,c4y;
	
	//ustawiamy nasze statki
	cout<< "usatw s1 x 0-9" <<endl;
	cin>>s1x;
	while(s1x>9) {
		cout<< "podaj s1 x 0-9" <<endl;
		cin>>s1x;
	}
	cout<< "usatw s1 y 0-9" <<endl;
	cin>>s1y;
	while(s1y>9) {
		cout<< "podaj s1 y 0-9" <<endl;
		cin>>s1y;
	}
	cout<< "usatw s2 x 0-9" <<endl;
	cin>>s2x;
	while(s2x>9) {
		cout<< "podaj s2 x 0-9" <<endl;
		cin>>s2x;
	}
	cout<< "usatw s2 y 0-9" <<endl;
	cin>>s2y;
	while(s2y>9) {
		cout<< "podaj s2 y 0-9" <<endl;
		cin>>s2y;
	}
	cout<< "usatw s3 x 0-9" <<endl;
	cin>>s3x;
	while(s3x>9) {
		cout<< "podaj s3 x 0-9" <<endl;
		cin>>s3x;
	}
	cout<< "usatw s3 y 0-9" <<endl;
	cin>>s3y;
	while(s3y>9) {
		cout<< "podaj s3 y 0-9" <<endl;
		cin>>s3y;
	}
	cout<< "usatw s4 x 0-9" <<endl;
	cin>>s4x;
	while(s4x>9) {
		cout<< "podaj s4 x 0-9" <<endl;
		cin>>s4x;
	}
	cout<< "usatw s4 y 0-9" <<endl;
	cin>>s4y;
	while(s4y>9) {
		cout<< "podaj s4 y 0-9" <<endl;
		cin>>s4y;
	}
	
	//losowanie pozycji statkow komputera
	c1x=rand()%10;
	c1y=rand()%10;
	c2x=rand()%10;
	c2y=rand()%10;
	c3x=rand()%10;
	c3y=rand()%10;
	c4x=rand()%10;
	c4y=rand()%10;
	//cout<<c1x<<c1y<<c2x<<c2y<<c3x<<c3y<<c4x<<c4y<<endl;
	
	//podawnaie pozycji sttakow komputera aby zatopic 4 statki
	while(gop<4 || goc<4) {
		cout<< "podaj kolumne 0-9" <<endl;
		cin>>k;
		while(k>9) {
			cout<< "podaj kolumne 0-9" <<endl;
			cin>>k;
		}
		cout<< "podaj wiersz 0-9" <<endl;
		cin>>w;
		while(w>9) {
			cout<< "podaj wiersz 0-9" <<endl;
			cin>>w;
		}

		plansza(k,w,s1x,s2x,s3x,s4x,s1y,s2y,s3y,s4y,c1x,c1y,c2x,c2y,c3x,c3y,c4x,c4y);
	}
	return 0;
}

