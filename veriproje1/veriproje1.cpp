#pragma region Kütüphaneler



#include<iostream>
#include<string>
#include<fstream>
#include<cstring>
#include<algorithm>//transform fonksiyonunun olduğu kütüphane
#include<chrono>//zaman fonksiyonunun olduğu kütüphane
#pragma endregion

#pragma region Namespaceler



using namespace std;
using namespace chrono;
#pragma endregion

#pragma region LISTE



struct mercan //xslt dosyası için oluşturulan liste
{
	mercan* next;
	mercan *prev;
	string data;

};
struct zehra  //txt dosyası için oluşturulan liste
{
	zehra* next;
	zehra* prev;
	string data;

};
struct meryem   //html dosyası için oluşturulan liste
{
	meryem* next;
	meryem* prev;
	string data;

};
struct dogukan  // css dosyası için oluşturulan liste
{
	dogukan* next;
	dogukan* prev;
	string data;

};
#pragma endregion

#pragma region LEVENSTHEIN

//yer ve zaman karmaşıklığı O(nxm)'dir.

int min(int x, int y, int z) {
	if (x <= y && x <= z) return x;
	if (y <= x && y <= z) return y;
	else return z;
}
int editDistance(char str1[], char str2[], int m, int n) {//levensthein  algoritması; eksik olma, fazla olma veya yanlış olma durumuna göre uzaklık değeri çıkarıyor.

	if (m == 0)// m nin kelime uzunluğu 0 olduğu durum
		return n;

	if (n == 0)//n nin kelime uzunluğu 0 olduğu durum
		return m;

	if (str1[m - 1] == str2[n - 1])//son harf doğruysa bir önceki harfi doğrulamak için fonksiyona son harfin bir solundakini gönderiyor.
		return editDistance(str1, str2, m - 1, n - 1);

	return 1 + min(editDistance(str1, str2, m, n - 1),//ekleme durumu
		editDistance(str1, str2, m - 1, n),//silme durumu
		editDistance(str1, str2, m - 1, n - 1));//yer değiştirme  durumu
}//return deki +1 boş kelime olma ihtimalinden geliyor.
#pragma endregion

#pragma region XSLT



mercan* ekle(mercan* kok, string x) {//xslt listeye ekleme
	if (kok == NULL)
	{
		kok = new mercan;
		kok->data = x;
		kok->next = kok;
		kok->prev = kok;
	}
	else
	{
		kok->prev->next = new mercan;
		kok->prev->next->data = x;
		kok->prev->next->next = kok;
		kok->prev->next->prev = kok->prev;
		kok->prev = kok->prev->next;
	}
	return kok;
}


void aramamercan(mercan* r, string aranan) {//xslt listede aratma
	if (r == NULL)
		cout << "liste bos";
	else
	{
		mercan* yrd;
		string a;
		int sayac = 0;
		string b;
		yrd = r;
		auto start = high_resolution_clock::now();//zaman başlangıcı
		while (yrd->next != r)
		{
			if (yrd->data == aranan) {
				auto stop = high_resolution_clock::now();//zaman bitişi
				auto duration = duration_cast<milliseconds>(stop - start);
				double a = duration.count();
				
				cout <<aranan<<" "<< a<< "  ms'de bulundu" << endl;
				sayac++;//yakın kelimeleri aratmamak için sayaç arttırılır.
				

			}

			yrd = yrd->next;



		}
		yrd = r;
		auto start1 = high_resolution_clock::now();//zaman başlangıcı
		while (yrd->next != r)
		{
			if (sayac == 0) {
				string a;
				a = yrd->data;
				char* str1 = (char*)aranan.c_str();
				char* str2 = (char*)a.c_str();
				if (editDistance(str1, str2, strlen(str1), strlen(str2)) <= 2) {
					auto stop1 = high_resolution_clock::now();//zaman bitişi
					auto duration = duration_cast<milliseconds>(stop1 - start1);
					double a = duration.count();
					
					cout << "Bunu mu demek istediniz = " << str2 << " " << a << "  ms'de bulundu. " << endl;
				}
			}
			yrd = yrd->next;
		}

	}
}
#pragma endregion

#pragma region HTML



meryem* ekle1(meryem* kok, string x) {//html dosyassını listeye ekleme
	if (kok == NULL)
	{
		kok = new meryem;
		kok->data = x;
		kok->next = kok;
		kok->prev = kok;
	}
	else
	{
		kok->prev->next = new meryem;
		kok->prev->next->data = x;
		kok->prev->next->next = kok;
		kok->prev->next->prev = kok->prev;
		kok->prev = kok->prev->next;
	}
	return kok;
}


void aramameryem(meryem* r, string aranan) {//html listesinde arama
	if (r == NULL)
		cout << "liste bos";
	else
	{
		meryem* yrd;
		string a;
		int sayac = 0;
		string b;
		yrd = r;
		auto start = high_resolution_clock::now();//zaman başlangıcı
		while (yrd->next != r)
		{
			if (yrd->data == aranan) {
				auto stop = high_resolution_clock::now();//zaman bitişi
				auto duration = duration_cast<milliseconds>(stop - start);
				double a = duration.count();
				
				cout << aranan << " "<<a << "  ms'de bulundu" << endl;
				sayac++;//yakın kelimeleri aratmamak için sayaç arttırılır.
				
			}

              yrd = yrd->next;

		}
		yrd = r;
		auto start1 = high_resolution_clock::now();//zaman başlangıcı
		while (yrd->next != r)
		{
			if (sayac == 0) {
				string a;
				a = yrd->data;
				char* str1 = (char*)aranan.c_str();
				char* str2 = (char*)a.c_str();
				if (editDistance(str1, str2, strlen(str1), strlen(str2)) <= 2) {
					auto stop1 = high_resolution_clock::now();//zaman bitişi
					auto duration = duration_cast<milliseconds>(stop1 - start1);
					double a = duration.count();
					
					cout << "Bunu mu demek istediniz = " << str2 <<"  "<<a<< "  ms'de bulundu. " << endl;
				}
			}
			yrd = yrd->next;
		}

	}
}
#pragma endregion

#pragma region TXT



	zehra* ekle3(zehra* kok, string x) {//txt dosyasını listeye ekleme fonksiyonu
	if (kok == NULL)
	{
		kok = new zehra;
		kok->data = x;
		kok->next = kok;
		kok->prev = kok;
	}
	else
	{
		kok->prev->next = new zehra;
		kok->prev->next->data = x;
		kok->prev->next->next = kok;
		kok->prev->next->prev = kok->prev;
		kok->prev = kok->prev->next;
	}
	return kok;
}


	void aramazehra(zehra* r, string aranan) {//txt listesinde arama
		if (r == NULL)
			cout << "liste bos";
		else
		{
			zehra* yrd;
			string a;
			int sayac = 0;
			string b;
			yrd = r;
			auto start1 = high_resolution_clock::now();//zaman başlangıcı
			while (yrd->next != r)
			{
				if (yrd->data == aranan) {
					auto stop1 = high_resolution_clock::now();//zaman bitişi
					auto duration = duration_cast<milliseconds>(stop1 - start1);
					double a = duration.count();
					
					cout << aranan << " "<< a << "  ms'de bulundu." << endl;
					sayac++;//yakın kelimeleri aratmamak için sayaç arttırılır.
				

				}

				yrd = yrd->next;
			}
			yrd = r;
			auto start = high_resolution_clock::now();//zaman başlangıcı
			while (yrd->next != r)
			{
				if (sayac == 0) {
					string a;
					a = yrd->data;
					char* str1 = (char*)aranan.c_str();
					char* str2 = (char*)a.c_str();
					if (editDistance(str1, str2, strlen(str1), strlen(str2)) <= 2) {
						auto stop = high_resolution_clock::now();//zaman bitişi
						auto duration = duration_cast<milliseconds>(stop - start);
						double a = duration.count();
						
						cout << "Bunu mu demek istediniz = " << str2 << " " << a << "  ms'de bulundu. " << endl;
					}
				}
				yrd = yrd->next;
			}

			}

		}
#pragma endregion	

#pragma region CSS



	dogukan* ekle4(dogukan * kok, string x) {//css dosyasnı listeye ekleyen fonksiyon
		if (kok == NULL)
		{
			kok = new dogukan;
			kok->data = x;
			kok->next = kok;
			kok->prev = kok;
		}
		else
		{
			kok->prev->next = new dogukan;
			kok->prev->next->data = x;
			kok->prev->next->next = kok;
			kok->prev->next->prev = kok->prev;
			kok->prev = kok->prev->next;
		}
		return kok;
	}


	void aramadogukan(dogukan* r, string aranan) {//css listesinde arama
		if (r == NULL)
			cout << "liste bos";
		else
		{
			dogukan* yrd;
			string a;
			int sayac = 0;
			string b;
			yrd = r;
			auto start1 = high_resolution_clock::now();//zaman başlangıcı
			while (yrd->next != r)
			{
				if (yrd->data == aranan) {
					auto stop1 = high_resolution_clock::now();//zaman birişi
					auto duration = duration_cast<milliseconds>(stop1 - start1);
					double a = duration.count();
					
					cout << aranan <<" "<<a<< "  ms'de bulundu" << endl;
					sayac++;//yakın kelimeleri aratmamak için sayaç arttırılır.
					

				}

				yrd = yrd->next;

			}
			yrd = r;
			auto start = high_resolution_clock::now();//zaman başlangıcı
			while (yrd->next != r)
			{
				if (sayac == 0) {
					string a;
					a = yrd->data;
					char* str1 = (char*)aranan.c_str();
					char* str2 = (char*)a.c_str();
					if (editDistance(str1, str2, strlen(str1), strlen(str2)) <= 2) {
						auto stop = high_resolution_clock::now();//zaman bitişi
						auto duration = duration_cast<milliseconds>(stop - start);
						double a = duration.count();
						
						cout << "Bunu mu demek istediniz = " << str2 << " " << a << "  ms'de bulundu. " << endl;
					}
				}
				yrd = yrd->next;
			}

		}
	}
	
#pragma endregion

void main() {

	zehra*   root  = NULL;
	mercan*  root1 = NULL;
	meryem*  root2 = NULL;
	dogukan* root3 = NULL;
#pragma region Dosyadanlisteye



	ifstream file("zehra.txt");
	string line;
	while (getline(file, line)) {//txt dosyasını okunup listeye ekleniyor.
	
		root = ekle3(root, line);
	}
	file.close();
	ifstream file1("meryem.htm");
	
	while (getline(file1, line,' ')) {//html dosyası okunup listeye ekleniyor.
		if (line != " ") {
			
			root2 = ekle1(root2, line);
		}
	}
	file1.close();




	ifstream file2("dogukan.css");//css dosyası okunup listeye ekleniyor.
	
	while (getline(file2, line,' ')) {
		root3 = ekle4(root3, line);
	}
	file2.close();
	ifstream file3("mercan.xslt");//xslt dosyası okunup listeye ekleniyor.
	
	while (getline(file3, line,' ')) {
		root1 = ekle(root1, line);
	}
	file3.close();
#pragma endregion
	baslangic:
	system("CLS");
	cout << "                                  NeyseBul Arama Motoruna Hosgeldiniz" << endl<<endl<<endl;




	cout << "                                      1-TXT   Dosyasinda Arama                  " << endl;
	cout << "                                      2-CSS   Dosyasinda Arama                  " << endl;
	cout << "                                      3-XSLT  Dosyasinda Arama                  " << endl;
	cout << "                                      4-Html  Dosyasinda Arama                  " << endl;
	cout << "                                      5-Butun Dosyalarda Arama                  " << endl;
	int secim;
	char secim1;
	cout << "Seciminizi Giriniz=";
	cin >> secim;
#pragma region SwitchCase



	switch (secim)
	{
	case 1: {
		string arama;
		cout << "Aramak Istediginiz Kelimeyi Giriniz=";
		cin >> arama;
		transform(arama.begin(), arama.end(), arama.begin(), ::tolower);//girilen stringi küçük harfe dönüştürüyor.
		aramazehra(root, arama);
		cout << "Tekrar Denemek Ister Misiniz?(e/h)";
		cin >> secim1;
		if (secim1 == 'e' || secim1 == 'E')
		
			goto baslangic;

		break;
	}


	case 2: {
		string arama;
		cout << "Aramak Istediginiz Kelimeyi Giriniz=";
		cin >> arama;
		transform(arama.begin(), arama.end(), arama.begin(), ::tolower);
		aramadogukan(root3, arama);
		cout << "Tekrar Denemek Ister Misiniz?(e/h)";
		cin >> secim1;
		if (secim1 == 'e' || secim1 == 'E')

			goto baslangic;
		break;
	}
     
	case 3: {
		string arama;
		cout << "Aramak Istediginiz Kelimeyi Giriniz=";
		cin >> arama;
		transform(arama.begin(), arama.end(), arama.begin(), ::tolower);
		aramamercan(root1, arama);
		cout << "Tekrar Denemek Ister Misiniz?(e/h)";
		cin >> secim1;
		if (secim1 == 'e' || secim1 == 'E')

			goto baslangic;
		break;
	}

	case 4: {
		string arama;
		cout << "Aramak Istediginiz Kelimeyi Giriniz=";
		cin >> arama;
		transform(arama.begin(), arama.end(), arama.begin(), ::tolower);
		aramameryem(root2, arama);
		cout << "Tekrar Denemek Ister Misiniz?(e/h)";
		cin >> secim1;
		if (secim1 == 'e' || secim1 == 'E')

			goto baslangic;
		break;
	}
	case 5: {
		string arama;
		cout << "Aramak Istediginiz Kelimeyi Giriniz=";
		cin >> arama;
		transform(arama.begin(), arama.end(), arama.begin(), ::tolower);
		cout << "Txt Dosyasında Bulunanlar" << endl<<endl;
		aramazehra(root, arama);
		cout <<endl<< "XSLT Dosyasında Bulunanlar" << endl<<endl;
        aramamercan(root1 ,arama);
		cout <<endl<< "HTML Dosyasında Bulunanlar" << endl<<endl;
		aramameryem(root2 ,arama);
		cout <<endl <<"CSS Dosyasında Bulunanlar" << endl<<endl;
		aramadogukan(root3,arama);
		cout <<endl<< "Tekrar Denemek Ister Misiniz?(e/h)";
		cin >> secim1;
		if (secim1 == 'e' || secim1 == 'E')

			goto baslangic;
		break;

	}

	default:
		break;



	}
#pragma endregion

}