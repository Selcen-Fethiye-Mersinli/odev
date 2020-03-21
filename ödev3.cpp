//Bu program 1,2 ya da 3 adım zıplayabilen bir kurbağanın maksimum 72 taşlı bir dereden karşıya geçebileceği kaç tane yol olduğunu hesaplar.
//Selcen Fethiye MERSİNLİ
#include <iostream>
#include <vector>
#include <iomanip>
#include <chrono>

using namespace std;

#define _TEST_ITERATIVE_
#define _TEST_RECURSIVE_

long long recursiveFunction(int numberOfStones)
{
	if (1 == numberOfStones) 
	{	//base case 1
		return 1;
	}
	else if (2 == numberOfStones) 
	{	//base case 2
		return 2;
	}
	else if (3 == numberOfStones) 
	{	//base case 3
		return 4;
	}
	else 
	{	//Bu kısım recursive kısımsır.
		//Memoization yapılır.
		//Ağaç formunda ilerleyen bir algoritmadır.
		//Her seferinde bizi geriye götürür.
		return recursiveFunction(numberOfStones - 1) + recursiveFunction(numberOfStones - 2) + recursiveFunction(numberOfStones - 3);
	}
}

long long iterativeFunction(int numberOfStones)
{
	vector<long long>yollar; //Gidilecek yolları tutan bir vektör tanımlanır
	yollar.push_back(1); 
	yollar.push_back(2);
	yollar.push_back(4); 
	//İlk üç eleman base case olduğu için onları yerine atar
	//push_back vektörün sonuna koymaya yarar

	long long toplam = yollar[0]+yollar[1]+yollar[2]; //Örüntüyü başlatabilmek için ilk üç elemanın toplamını tut 
	long long oruntu_degiskeni; //Örüntünün sağlanması için gerekli

	for (int i = 1;i < numberOfStones;++i)
	{
		yollar.push_back(toplam); //bir önceki üç sayının toplamı o konumdaki sayıyı verir
		oruntu_degiskeni = yollar[i-1]; //döngünün başından itibaren sırası ile bir sonraki indisi tutar
		toplam = toplam * 2 - oruntu_degiskeni; //Her seferinde toplamın iki katınından örüntünün (i-1). indisini çıkararak örüntüyü olusturur
	}
	return yollar[numberOfStones-1]; //Her bulduğu indisi geri gönderir
}



int main()
{
	const int MAX_NUMBER_OF_STONES{ 72 };

	cout << setfill(' ');

	cout.imbue(locale(""));

	for (auto i = 1; i < MAX_NUMBER_OF_STONES; ++i)
	{

#ifdef _TEST_ITERATIVE_
		{
			long long tempResult = { 0 };

			auto start = std::chrono::steady_clock::now();
			tempResult = iterativeFunction(i);
			auto stop = std::chrono::steady_clock::now();
			auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();


			cout << "iterative" << setw(4) << i << " -> " << tempResult << " ( " << duration << "us )\n";
		}
#endif

#ifdef _TEST_RECURSIVE_
		{
			long long tempResult = { 0 };

			auto start = std::chrono::steady_clock::now();
			tempResult = recursiveFunction(i);
			auto stop = std::chrono::steady_clock::now();
			auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();

			cout << "recursive" << setw(4) << i << " -> " << tempResult << "\t( " << duration << "us )\n\n";
		}
#endif

	}

	return 0;
}
