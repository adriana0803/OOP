//tema:Gestiunea unui service de montare anvelope (M,V si A)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include<fstream>
using namespace std;

class Anvelope
{
private:
	string sezon = "Necunoscut";
	int dimensiune = 0;
	char* producator = NULL;
	int nrMagazine = 0;
	float* pretPerMagazin = nullptr;

public:
	//constructor cu un parametru
	Anvelope(const char* producator)
	{
		this->producator = new char[strlen(producator) + 1];
		strcpy(this->producator, producator);
		this->sezon = "necunoscut";
		this->dimensiune = 0;
		this->nrMagazine = 0;
		this->pretPerMagazin = nullptr;
	}

	//constructor cu toti parametri
	Anvelope(string sezon, int dimensiune, const char* producator, int nrMagazine, float* pretPerMagazin)
	{
		this->producator = new char[strlen(producator) + 1];
		strcpy(this->producator, producator);
		this->sezon = sezon;
		this->dimensiune = dimensiune;
		this->nrMagazine = nrMagazine;
		if (nrMagazine > 0 && pretPerMagazin != nullptr)
			this->nrMagazine = nrMagazine;
		this->pretPerMagazin = new float[this->nrMagazine];
		for (int i = 0; i < this->nrMagazine; i++)
		{
			this->pretPerMagazin[i] = pretPerMagazin[i];
		}
	}

	//constructor de copiere
	Anvelope(const Anvelope& a)
	{
		this->producator = new char[strlen(a.producator) + 1];
		strcpy(this->producator, a.producator);
		this->sezon = a.sezon;
		this->dimensiune = a.dimensiune;
		this->nrMagazine = a.nrMagazine;
		if (a.nrMagazine > 0 && a.pretPerMagazin != nullptr)
		{
			this->nrMagazine = a.nrMagazine;
			this->pretPerMagazin = new float[a.nrMagazine];
			for (int i = 0; i < a.nrMagazine; i++)
			{
				this->pretPerMagazin[i] = a.pretPerMagazin[i];
			}
		}
	}

	//operator =
	Anvelope& operator=(const Anvelope& a)
	{
		if (this != &a)
		{
			delete[] this->producator;
			delete[] this->pretPerMagazin;
			this->producator = new char[strlen(a.producator) + 1];
			strcpy(this->producator, a.producator);
			this->sezon = a.sezon;
			this->dimensiune = a.dimensiune;
			this->nrMagazine = a.nrMagazine;
			if (a.nrMagazine > 0 && a.pretPerMagazin != nullptr)
			{
				this->nrMagazine = a.nrMagazine;
				this->pretPerMagazin = new float[a.nrMagazine];
				for (int i = 0; i < a.nrMagazine; i++)
				{
					this->pretPerMagazin[i] = a.pretPerMagazin[i];
				}
			}

		}
		return *this;
	}

	//operator ==
	bool operator==(const Anvelope& a)
	{
		if (dimensiune == a.dimensiune && sezon == a.sezon)
		{
			return true;
		}
		else
			return false;
	}

	//getteri
	string getSezon()
	{
		return this->sezon;
	}

	int getDimensiune()
	{
		return this->dimensiune;
	}

	char* getProducator()
	{
		return this->producator;
	}

	int getNrMagazine()
	{
		return this->nrMagazine;
	}

	float* getPretPerMagazin()
	{
		return this->pretPerMagazin;
	}

	//setteri
	void setSezon(string sezon)
	{
		if (sezon.length() > 0)
		{
			this->sezon = sezon;
		}
	}

	void setDimensiune(int dimensiune)
	{
		if (dimensiune > 1)
		{
			this->dimensiune = dimensiune;
		}
	}

	void setProducator(const char* producator)
	{
		if (strlen(producator) > 1)
			delete[] this->producator;
		this->producator = new char[strlen(producator) + 1];
		strcpy(this->producator, producator);
	}

	void setNrMagazine(int nrMagazine)
	{
		if (nrMagazine > 0)
		{
			this->nrMagazine = nrMagazine;
		}
	}

	void setPretPerMagazin(int nrMagazine, float* pretPerMagazin)
	{
		if (nrMagazine > 0 && pretPerMagazin != nullptr)
		{
			delete[] this->pretPerMagazin;
			this->nrMagazine = nrMagazine;
			this->pretPerMagazin = new float[nrMagazine];
			for (int i = 0; i < nrMagazine; i++)
			{
				this->pretPerMagazin[i] = pretPerMagazin[i];
			}
		}
	}

	//operatorul []
	float& operator[](int index)
	{
		if (index >= 0 && index < this->nrMagazine)
		{
			return this->pretPerMagazin[index];
		}
	}

	//operator !
	bool operator!()
	{
		if (this->nrMagazine > 0)
		{
			return true;
		}
		return false;
	}

	//operator ++ pre incrementare
	Anvelope& operator++()
	{
		this->dimensiune++;
		return *this;
	}

	//operator ++ post incrementare
	Anvelope operator++(int)
	{
		Anvelope rez = *this;
		this->dimensiune++;
		return rez;
	}

	//operator >
	bool operator>(Anvelope a)
	{
		return this->dimensiune > a.dimensiune;
	}

	//operator cast
	explicit operator int()
	{
		return this->dimensiune;
	}

	//operator <<
	friend ostream& operator<<(ostream& out, Anvelope& a)
	{
		out << "\n-----------------------------";
		out << "\nSezon: " << a.sezon << endl;
		out << "\nDimensiune: " << a.dimensiune << endl;
		out << "\nProducator: " << a.producator << endl;
		out << "\n Numar magazine: " << a.nrMagazine << endl;
		out << "\n Preturi pentru fiecare magazin: ";
		for (int i = 0; i < a.nrMagazine; i++)
			out << a.pretPerMagazin[i] << " ";
		out << "\n-----------------------------";
		return out;
	}

	//operator >>
	friend istream& operator>>(istream& in, Anvelope& a)
	{
		delete[] a.producator;
		delete[] a.pretPerMagazin;

		cout << "\nIntroduceti sezonul: ";
		in >> a.sezon;
		cout << "\nIntroduceti dimensiunea: ";
		in >> a.dimensiune;
		cout << "\nIntroduceti numele producatorului: ";
		char auxprod[100];
		in >> auxprod;
		a.producator = new char[strlen(auxprod) + 1];
		strcpy(a.producator, auxprod);
		cout << "\nIntroduceti numarul de magazine: ";
		in >> a.nrMagazine;
		a.pretPerMagazin = new float[a.nrMagazine];
		for (int i = 0; i < a.nrMagazine; i++)
		{
			cout << "Pretul din magazinul " << i + 1 << ":";
			in >> a.pretPerMagazin[i];
		}
		return in;
	}

	//functie de afisare
	void afisare()
	{
		cout << "\n-----------------------------";
		cout << "\nSezon: " << this->sezon;
		cout << "\nDimensiune: " << this->dimensiune;
		cout << "\nProducator: " << this->producator;
		cout << "\nNumar magazine: " << this->nrMagazine;
		cout << "\nPret per magazin: ";
		for (int i = 0; i < this->nrMagazine; i++)
			cout << this->pretPerMagazin[i] << " ";
		cout << "\n-----------------------------";
	}


	//serializare
	void serializare()
	{
		ofstream f("anvelope.bin", ios::binary);
		f.write((char*)&sezon, sizeof(sezon));
		f.write((char*)&dimensiune, sizeof(dimensiune));
		f.write((char*)&producator, sizeof(producator));
		f.write((char*)&nrMagazine, sizeof(nrMagazine));
		if (pretPerMagazin != NULL)
		{
			for (int i = 0; i < nrMagazine; i++)
			{
				f.write((char*)&pretPerMagazin[i], sizeof(pretPerMagazin[i]));
			}
		}
		f.close();
	}



	//deserializare
	void deserializare()
	{
		ifstream f("anvelope.bin", ios::binary);
		int length = 0;
		f.read((char*)&sezon, sizeof(sezon));
		f.read((char*)&dimensiune, sizeof(dimensiune));
		f.read((char*)&length, sizeof(length));
		char* buffer = new char[length + 1];
		f.read(buffer, length + 1);
		delete[]producator;
		producator = new char[length + 1];
		strcpy_s(producator, length + 1, buffer);
		delete[] buffer;
		f.read((char*)&nrMagazine, sizeof(nrMagazine));
		delete[] pretPerMagazin;
		pretPerMagazin = new float[nrMagazine];
		if (pretPerMagazin != NULL)
		{
			for (int i = 0; i < nrMagazine; i++)
			{
				f.read((char*)&pretPerMagazin[i], sizeof(pretPerMagazin[i]));
			}
		}
		f.close();
	}

	//citire din fisier txt
	friend ofstream& operator<<(ofstream& out, Anvelope& a)
	{
		out << "\n---------------------------------------";
		out << "\nSezon: " << a.sezon;
		out << "\nDimensiune anvelope : " << a.dimensiune;
		out << "\nProducator: " << a.producator;
		out << "\nNumar magazine: " << a.nrMagazine;
		out << "\nPretul in fiecare magazin: ";
		for (int i = 0; i < a.nrMagazine; i++)
			out << a.pretPerMagazin[i] << " ";
		out << "\n---------------------------------------";

		return out;
	}

	//scriere fisier txt
	friend ifstream& operator>>(ifstream& in, Anvelope& a)
	{
		in >> a.sezon;
		in >> a.dimensiune;
		if (a.producator != NULL)
			delete[] a.producator;
		char aux[200];
		in.getline(aux, 199);
		a.producator = new char[strlen(aux) + 1];
		strcpy(a.producator, aux);
		in >> a.nrMagazine;
		if (a.pretPerMagazin != NULL)
			delete[] a.pretPerMagazin;
		a.pretPerMagazin = new float[a.nrMagazine];
		for (int i = 0; i < a.nrMagazine; i++)
			in >> a.pretPerMagazin[i];

		return in;
	}

	/*string sezon = "Necunoscut";
int dimensiune = 0;
char* producator = NULL;
int nrMagazine = 0;
float* pretPerMagazin = nullptr;*/

//exportare in fisier CSV
	void exportCSV(string numeFisierCSV)
	{
		ofstream f(numeFisierCSV, ios::app);
		f << this->sezon << ",";
		f << this->dimensiune << ",";
		f << this->producator << ",";
		f << this->nrMagazine << ",";
		for (int i = 0; i < nrMagazine; i++)
		{
			f << this->pretPerMagazin[i] << ",";
		}
		f << endl;
		f.close();
	}

	//importare din fisier CSV
	void importCSV(string numeFisierCSV)
	{
		ifstream f(numeFisierCSV, ios::in);
		if (f.is_open())
		{
			cout << "Sezon: ";
			f >> this->sezon;
			cout << "Dimensiune anvelope: ";
			f >> this->dimensiune;
			if (this->producator != NULL)
				delete[] this->producator;
			cout << "Producator: ";
			char aux[200];
			f.getline(aux, 199, ',');
			this->producator = new char[strlen(aux) + 1];
			strcpy(this->producator, aux);
			cout << "Numar magazine: ";
			f >> this->nrMagazine;
			if (this->pretPerMagazin != NULL)
				delete[] this->pretPerMagazin;
			this->pretPerMagazin = new float[this->nrMagazine];
			for (int i = 0; i < this->nrMagazine; i++)
				f >> this->pretPerMagazin[i];
		}
		else
			cout << "Fisierul CSV nu exista";
	}


	//destructor
	~Anvelope()
	{
		delete[] this->producator;
		delete[] this->pretPerMagazin;
	}

};

class Angajat
{
protected:
	static int nrAngajati;
	const int idAngajat;
	char* nume = NULL;
	float salariu = 0;
	int aniVechime = 0;
	int nrZileLucrate = 0;
	int* zileLucrate = nullptr;


public:
	//constructor fara parametri
	Angajat() :idAngajat(0)
	{
	}

	//constructor cu un parametru
	Angajat(const char* nume) :idAngajat(0)
	{
		nrAngajati++;
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
		this->salariu = 0;
		this->aniVechime = 0;
		this->nrZileLucrate = 0;
		this->zileLucrate = nullptr;
	}

	//constructor cu toti parametri
	Angajat(int idAngajat, const char* nume, float salariu, int aniVechime, int nrZileLucrate, int* zileLucrate) :idAngajat(idAngajat)
	{
		nrAngajati++;
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
		this->salariu = salariu;
		this->aniVechime = aniVechime;
		this->nrZileLucrate = nrZileLucrate;
		this->zileLucrate = new int[this->nrZileLucrate];
		for (int i = 0; i < this->nrZileLucrate; i++)
		{
			this->zileLucrate[i] = zileLucrate[i];
		}
	}

	//constructor de copiere
	Angajat(const Angajat& a) :idAngajat(a.idAngajat)
	{
		nrAngajati++;
		this->nume = new char[strlen(a.nume) + 1];
		strcpy(this->nume, a.nume);
		this->salariu = a.salariu;
		this->aniVechime = a.aniVechime;
		this->nrZileLucrate = a.nrZileLucrate;
		this->zileLucrate = new int[a.nrZileLucrate];
		for (int i = 0; i < a.nrZileLucrate; i++)
		{
			this->zileLucrate[i] = a.zileLucrate[i];
		}
	}

	//operatorul =
	Angajat& operator=(const Angajat& a)
	{
		if (this != &a)
		{
			delete[] this->nume;
			delete[] this->zileLucrate;
			this->nume = new char[strlen(a.nume) + 1];
			strcpy(this->nume, a.nume);
			this->salariu = a.salariu;
			this->aniVechime = a.aniVechime;
			if (nrZileLucrate > 0 && zileLucrate != nullptr)
			{

				this->nrZileLucrate = a.nrZileLucrate;
				this->zileLucrate = new int[a.nrZileLucrate];
				for (int i = 0; i < a.nrZileLucrate; i++)
				{
					this->zileLucrate[i] = a.zileLucrate[i];
				}
			}
		}
		return *this;
	}

	//operatorul ==
	bool operator==(const Angajat& a)
	{
		if (aniVechime == a.aniVechime && salariu == a.salariu)
		{
			return true;
		}
		else
			return false;
	}


	//getteri
	static int getNrAngajati()
	{
		return Angajat::nrAngajati;
	}

	int getIdAngajat()
	{
		return this->idAngajat;
	}

	char* getNume()
	{
		return this->nume;
	}

	float getSalariu()
	{
		return this->salariu;
	}

	int getAniVechime()
	{
		return this->aniVechime;
	}

	int getNrZileLucrate()
	{
		return this->nrZileLucrate;
	}

	int* getZileLucrate()
	{
		return this->zileLucrate;
	}

	//setteri
	void setNume(const char* nume)
	{
		if (strlen(nume) > 1)
			delete[] this->nume;
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
	}

	void setSalariu(float salariu)
	{
		if (salariu > 0)
		{
			this->salariu = salariu;
		}
	}

	void setAniVechime(int aniVechime)
	{
		if (aniVechime > 0)
		{
			this->aniVechime = aniVechime;
		}
	}

	void setNrZileLucrate(int nrZileLucrate)
	{
		if (nrZileLucrate > 0)
		{
			this->nrZileLucrate = nrZileLucrate;
		}
	}

	void setZileLucrate(int nrZileLucrate, int* zileLucrate)
	{
		if (nrZileLucrate > 0 && zileLucrate != nullptr)
			delete[] this->zileLucrate;
		this->nrZileLucrate = nrZileLucrate;
		this->zileLucrate = new int[nrZileLucrate];
		for (int i = 0; i < nrZileLucrate; i++)
		{
			this->zileLucrate[i] = zileLucrate[i];
		}
	}

	//operator []
	int& operator[](int index)
	{
		if (index >= 0 && index < this->nrZileLucrate)
		{
			return this->zileLucrate[index];
		}
	}

	//operator !
	bool operator!()
	{
		if (this->nrAngajati > 0)
		{
			return true;
		}
		return false;
	}

	//operator ++ pre incrementare
	Angajat& operator++()
	{
		this->aniVechime++;
		return *this;
	}

	//operator ++ post incrementare
	Angajat operator++(int)
	{
		Angajat rez = *this;
		this->aniVechime++;
		return rez;
	}

	//operator >
	bool operator>(Angajat a)
	{
		return this->salariu > a.salariu;
	}

	//operator cast
	explicit operator int()
	{
		return this->aniVechime;
	}

	//operator <<
	friend ostream& operator<<(ostream& out, Angajat& a)
	{
		out << "\n---------------------------------------";
		out << "\nId angajat: " << a.idAngajat;
		out << "\nNume: " << a.nume;
		out << "\nSalariu: " << a.salariu;
		out << "\nAni vechime: " << a.aniVechime;
		out << "\nNumar zile lucrate: " << a.nrZileLucrate;
		out << "\nZile lucrate: ";
		for (int i = 0; i < a.nrZileLucrate; i++)
			out << a.zileLucrate[i] << " ";
		out << "\n---------------------------------------";

		return out;
	}

	//operator >>
	friend istream& operator>>(istream& in, Angajat& a)
	{
		delete[] a.nume;
		delete[] a.zileLucrate;

		cout << "\nIntroduceti numele angajatului: ";
		char auxnume[100];
		in >> auxnume;
		a.nume = new char[strlen(auxnume) + 1];
		strcpy(a.nume, auxnume);
		cout << "\nIntroduceti salariul: ";
		in >> a.salariu;
		cout << "\nIntroduceti ani vechime: ";
		in >> a.aniVechime;
		cout << "\nIntroduceti numarul de zile lucrate: ";
		in >> a.nrZileLucrate;
		a.zileLucrate = new int[a.nrZileLucrate];
		for (int i = 0; i < a.nrZileLucrate; i++)
		{
			cout << "Ziua " << i + 1 << " lucrata: ";
			in >> a.zileLucrate[i];
		}
		return in;
	}

	//functie de afisare
	void afisare()
	{
		cout << "\n---------------------------------------";
		cout << "\nID angajat: " << this->idAngajat;
		cout << "\nNume angajat: " << this->nume;
		cout << "\nSalariu angajat: " << this->salariu;
		cout << "\nAni vechime angajat: " << this->aniVechime;
		cout << "\nNumarul zilelor lucrate: " << this->nrZileLucrate;
		cout << "\nZile lucrate: ";
		for (int i = 0; i < this->nrZileLucrate; i++)
			cout << this->zileLucrate[i] << " ";
		cout << "\n---------------------------------------";
	}


	//serializare 
	void serializare()
	{
		ofstream f("angajat.bin", ios::binary);
		f.write((char*)&nume, sizeof(nume));
		f.write((char*)&salariu, sizeof(salariu));
		f.write((char*)&aniVechime, sizeof(aniVechime));
		f.write((char*)&nrZileLucrate, sizeof(nrZileLucrate));
		if (zileLucrate != NULL) {
			for (int i = 0; i < nrZileLucrate; i++) {
				f.write((char*)&zileLucrate[i], sizeof(zileLucrate[i]));
			}
		}
		f.close();
	}

	void deserializare()
	{
		ifstream f("angajat.bin", ios::binary);
		/*int length = 0;
		f.read((char*)&length, sizeof(length));
		char* buffer = new char[length + 1];
		f.read(buffer, length + 1);
		delete[] nume;
		nume = new char[length + 1];
		strcpy_s(nume, length + 1, buffer);
		delete[] buffer;*/
		if (this->nume != NULL)
			delete[] this->nume;
		int length = 0;
		f.read((char*)&length, sizeof(length));
		this->nume = new char[length + 1];
		f.read(this->nume, length + 1);
		f.read((char*)&salariu, sizeof(salariu));
		f.read((char*)&aniVechime, sizeof(aniVechime));
		f.read((char*)&nrZileLucrate, sizeof(nrZileLucrate));

		if (zileLucrate != NULL)
		{
			delete[] zileLucrate;
		}
		zileLucrate = new int[nrZileLucrate];
		for (int i = 0; i < nrZileLucrate; i++)
		{
			f.read((char*)&zileLucrate[i], sizeof(zileLucrate[i]));
		}
		f.close();
	}


	//citire din fisier txt
	friend ofstream& operator<<(ofstream& out, Angajat& a)
	{
		out << "\n---------------------------------------";
		out << "\nId angajat: " << a.idAngajat;
		out << "\nNume: " << a.nume;
		out << "\nSalariu: " << a.salariu;
		out << "\nAni vechime: " << a.aniVechime;
		out << "\nNumar zile lucrate: " << a.nrZileLucrate;
		out << "\nZile lucrate: ";
		for (int i = 0; i < a.nrZileLucrate; i++)
			out << a.zileLucrate[i] << " ";
		out << "\n---------------------------------------";

		return out;
	}


	//scriere in fisier txt
	friend ifstream& operator>>(ifstream& in, Angajat& a)
	{
		in >> ws;
		if (a.nume != NULL)
			delete[] a.nume;
		char aux[200];
		in.getline(aux, 199);
		a.nume = new char[strlen(aux) + 1];
		strcpy(a.nume, aux);
		in >> a.salariu;
		in >> a.aniVechime;
		in >> a.nrZileLucrate;
		if (a.zileLucrate != NULL)
			delete[] a.zileLucrate;
		a.zileLucrate = new int[a.nrZileLucrate];
		for (int i = 0; i < a.nrZileLucrate; i++)
			in >> a.zileLucrate[i];

		return in;
	}

	//exportare in fisier CSV
	void exportCSV(string numeFisierCSV)
	{
		ofstream f(numeFisierCSV, ios::app);
		f << this->idAngajat << ",";
		f << this->nume << ",";
		f << this->salariu << ",";
		f << this->aniVechime << ",";
		f << this->nrZileLucrate << ",";
		for (int i = 0; i < nrZileLucrate; i++)
		{
			f << this->zileLucrate[i] << ",";
		}
		f << endl;
		f.close();
	}


	//importare din fisier CSV
	void importCSV(string numeFisierCSV)
	{
		ifstream f(numeFisierCSV, ios::in);
		if (f.is_open())
		{
			if (this->nume != NULL)
				delete[] this->nume;
			cout << "Nume: ";
			char aux[200];
			f.getline(aux, 199, ',');
			this->nume = new char[strlen(aux) + 1];
			strcpy(this->nume, aux);
			cout << "Salariu: ";
			f >> this->salariu;
			cout << "Ani vechime: ";
			f >> this->aniVechime;
			cout << "Numar zile lucrate: ";
			f >> this->nrZileLucrate;
			if (this->zileLucrate != NULL)
				delete[] this->zileLucrate;
			this->zileLucrate = new int[this->nrZileLucrate];
			for (int i = 0; i < this->nrZileLucrate; i++)
				f >> this->zileLucrate[i];
		}
		else
			cout << "Fisierul CSV nu exista";
	}



	//destructor
	~Angajat()
	{
		delete[] this->nume;
		delete[] this->zileLucrate;
		nrAngajati--;
	}

};
int Angajat::nrAngajati = 0;

class Autovehicul
{
private:
	char* marca = NULL;
	string model = "Necunoscut";
	string culoare = "Necunoscuta";
	int nrAnvelope = 0;
	int* dimensiuniAnvelope = nullptr;
	const string serieSasiu;


public:
	//constructor fara parametri
	Autovehicul() :serieSasiu("Necunoscuta")
	{

	}

	//constructor cu un parametru
	Autovehicul(string serieSasiu) :serieSasiu(serieSasiu)
	{
		this->marca = new char[strlen("Necunoscuta") + 1];
		strcpy(marca, "Necunoscuta");
		this->model = "Necunoscut";
		this->culoare = "Necunoscuta";
		this->nrAnvelope = 0;
		this->dimensiuniAnvelope = nullptr;
	}

	//constructor cu toti parametri
	Autovehicul(string serieSasiu, const char* marca, string model, string culoare, int nrAnvelope, int* dimensiuniAnvelope) :serieSasiu(serieSasiu)
	{
		this->marca = new char[strlen(marca) + 1];
		strcpy(this->marca, marca);
		this->model = model;
		this->culoare = culoare;
		this->nrAnvelope = nrAnvelope;
		if (nrAnvelope > 0 && dimensiuniAnvelope != nullptr)
		{
			this->nrAnvelope = nrAnvelope;
			this->dimensiuniAnvelope = new int[this->nrAnvelope];
			for (int i = 0; i < this->nrAnvelope; i++)
			{
				this->dimensiuniAnvelope[i] = dimensiuniAnvelope[i];
			}
		}
	}

	//constructorul de copiere
	Autovehicul(const Autovehicul& a) :serieSasiu(a.serieSasiu)
	{
		this->marca = new char[strlen(a.marca) + 1];
		strcpy(this->marca, a.marca);
		this->model = a.model;
		this->culoare = a.culoare;
		this->nrAnvelope = a.nrAnvelope;
		if (a.nrAnvelope > 0 && a.dimensiuniAnvelope != nullptr)
		{
			this->nrAnvelope = a.nrAnvelope;
			this->dimensiuniAnvelope = new int[a.nrAnvelope];
			for (int i = 0; i < a.nrAnvelope; i++)
			{
				this->dimensiuniAnvelope[i] = a.dimensiuniAnvelope[i];
			}
		}
	}

	//operatorul =
	Autovehicul& operator=(const Autovehicul& a)
	{
		if (this != &a)
		{
			delete[] this->marca;
			delete[] this->dimensiuniAnvelope;

			this->marca = new char[strlen(a.marca) + 1];
			strcpy(this->marca, a.marca);
			this->model = a.model;
			this->culoare = a.culoare;
			this->nrAnvelope = a.nrAnvelope;
			if (a.nrAnvelope > 0 && a.dimensiuniAnvelope != nullptr)
			{
				this->nrAnvelope = a.nrAnvelope;
				this->dimensiuniAnvelope = new int[a.nrAnvelope];
				for (int i = 0; i < a.nrAnvelope; i++)
				{
					this->dimensiuniAnvelope[i] = a.dimensiuniAnvelope[i];
				}
			}

		}
		return *this;
	}

	//operator ==
	bool operator==(const Autovehicul& a)
	{
		if (model == a.model && culoare == a.culoare)
		{
			return true;
		}
		else
			return false;
	}

	//getteri
	string getSerieSasiu()
	{
		return this->serieSasiu;
	}

	char* getMarca()
	{
		return this->marca;
	}

	string getModel()
	{
		return this->model;
	}

	string getCuloare()
	{
		return this->culoare;
	}

	int getNrAnvelope()
	{
		return this->nrAnvelope;
	}

	int* getDimensiuniAnvelope()
	{
		return this->dimensiuniAnvelope;
	}


	//setteri
	void setMarca(const char* marca)
	{
		if (strlen(marca) > 1)
		{
			delete[] this->marca;
			this->marca = new char[strlen(marca) + 1];
			strcpy(this->marca, marca);
		}
	}

	void setModel(string model)
	{
		if (model.length() > 0)
		{
			this->model = model;
		}
	}

	void setCuloare(string culoare)
	{
		if (culoare.length() > 0)
		{
			this->culoare = culoare;
		}
	}

	void setNrAnvelope(int nrAnvelope)
	{
		if (nrAnvelope > 0)
		{
			this->nrAnvelope = nrAnvelope;
		}
	}

	void setDimensiuniAnvelope(int nrAnvelope, int* dimensiuniAnvelope)
	{
		if (nrAnvelope > 0 && dimensiuniAnvelope != nullptr)
		{
			delete[] this->dimensiuniAnvelope;
			this->nrAnvelope = nrAnvelope;
			this->dimensiuniAnvelope = new int[nrAnvelope];
			for (int i = 0; i < nrAnvelope; i++)
				this->dimensiuniAnvelope[i] = dimensiuniAnvelope[i];
		}
	}



	//operatorul []
	int& operator[](int index)
	{
		if (index >= 0 && index < this->nrAnvelope)
		{
			return this->dimensiuniAnvelope[index];
		}
	}

	//operatorul !
	bool operator!()
	{
		if (this->nrAnvelope > 0)
		{
			return true;
		}
		return false;
	}

	//operator++ pre incrementare
	Autovehicul& operator++()
	{
		int* vn = new int[this->nrAnvelope + 1];
		for (int i = 0; i < this->nrAnvelope; i++)
		{
			vn[i] = this->dimensiuniAnvelope[i];
		}
		vn[this->nrAnvelope] = 0;
		delete[] this->dimensiuniAnvelope;

		this->dimensiuniAnvelope = vn;
		this->nrAnvelope++;

		return *this;

	}

	//operator++ post incrementare
	Autovehicul operator++(int)
	{
		Autovehicul rez = *this;

		int* vn = new int[this->nrAnvelope + 1];
		for (int i = 0; i < this->nrAnvelope; i++)
		{
			vn[i] = this->dimensiuniAnvelope[i];
		}
		vn[this->nrAnvelope] = 0;
		delete[] this->dimensiuniAnvelope;

		this->dimensiuniAnvelope = vn;
		this->nrAnvelope++;

		return rez;
	}

	//operator >
	bool operator>(Autovehicul a)
	{
		return this->nrAnvelope > a.nrAnvelope;
	}

	//operator cast
	explicit operator int()
	{
		return this->nrAnvelope;
	}

	//operator <<
	friend ostream& operator<<(ostream& out, Autovehicul& a)
	{
		out << "\n---------------------------------------";
		out << "\nSerie sasiu: " << a.serieSasiu;
		out << "\nModel: " << a.model;
		out << "\nCuloare: " << a.culoare;
		out << "\nNumar anvelope: " << a.nrAnvelope;
		out << "\nDimensiuni anvelope: ";
		for (int i = 0; i < a.nrAnvelope; i++)
			out << a.dimensiuniAnvelope[i] << " ";
		out << "\n---------------------------------------";

		return out;
	}


	//operator >>
	friend istream& operator>>(istream& in, Autovehicul& a)
	{
		delete[] a.marca;
		delete[] a.dimensiuniAnvelope;

		cout << "\nIntroduceti numele marcii: ";
		char auxmarca[100];
		in >> auxmarca;
		a.marca = new char[strlen(auxmarca) + 1];
		strcpy(a.marca, auxmarca);
		cout << "\nIntroduceti modelul: ";
		in >> a.model;
		cout << "\nIntroduceti culoarea: ";
		in >> a.culoare;
		cout << "\nIntroduceti numarul de anvelope: ";
		in >> a.nrAnvelope;
		a.dimensiuniAnvelope = new int[a.nrAnvelope];
		for (int i = 0; i < a.nrAnvelope; i++)
		{
			cout << "Dimensiune pentru anvelopa " << i + 1 << ": ";
			in >> a.dimensiuniAnvelope[i];
		}
		return in;
	}

	//functia de afisare
	void afisare()
	{
		cout << "\n-----------------------------";
		cout << "\nSerie sasiu: " << this->serieSasiu;
		cout << "\nMarca: " << this->marca;
		cout << "\nModel: " << this->model;
		cout << "\nCuloare: " << this->culoare;
		cout << "\nNumar anvelope: " << this->nrAnvelope;
		cout << "\nDimensiuni anvelope: ";
		for (int i = 0; i < this->nrAnvelope; i++)
			cout << this->dimensiuniAnvelope[i] << " ";
		cout << "\n-----------------------------";
	}
	//serializare
	void serializare()
	{
		ofstream f("autovehicule.bin", ios::binary);
		f.write((char*)&marca, sizeof(marca));
		f.write((char*)&model, sizeof(model));
		f.write((char*)&culoare, sizeof(culoare));
		f.write((char*)&nrAnvelope, sizeof(nrAnvelope));
		if (dimensiuniAnvelope != NULL)
		{
			for (int i = 0; i < nrAnvelope; i++)
			{
				f.write((char*)&dimensiuniAnvelope[i], sizeof(dimensiuniAnvelope[i]));
			}
		}
		f.close();
	}

	//deserializare
	void deserializare()
	{
		ifstream f("autovehicul.bin", ios::binary);
		int length = 0;
		f.read((char*)&length, sizeof(length));
		char* buffer = new char[length + 1];
		f.read(buffer, length + 1);
		delete[] marca;
		marca = new char[length + 1];
		strcpy_s(marca, length + 1, buffer);
		delete[] buffer;
		f.read((char*)&model, sizeof(model));
		f.read((char*)&culoare, sizeof(culoare));
		f.read((char*)&nrAnvelope, sizeof(nrAnvelope));

		delete[] dimensiuniAnvelope;
		dimensiuniAnvelope = new int[nrAnvelope];
		if (dimensiuniAnvelope != NULL) {
			for (int i = 0; i < nrAnvelope; i++) {
				f.read((char*)&dimensiuniAnvelope[i], sizeof(dimensiuniAnvelope[i]));
			}
		}
		f.close();
	}



	//citire din fisier txt
	friend ofstream& operator<<(ofstream& out, Autovehicul& a)
	{
		out << "\n---------------------------------------";
		out << "\nMarca: " << a.marca;
		out << "\nModel: " << a.model;
		out << "\nCuloare: " << a.culoare;
		out << "\nNumar anvelope: " << a.nrAnvelope;
		out << "\nDimensiunile anvelopelor: ";
		for (int i = 0; i < a.nrAnvelope; i++)
			out << a.dimensiuniAnvelope[i] << " ";
		out << "\n---------------------------------------";

		return out;
	}

	//scriere fisier txt
	friend ifstream& operator>>(ifstream& in, Autovehicul& a)
	{
		if (a.marca != NULL)
			delete[] a.marca;
		char aux[200];
		in.getline(aux, 199);
		a.marca = new char[strlen(aux) + 1];
		strcpy(a.marca, aux);
		in >> a.model;
		in >> a.culoare;
		in >> a.nrAnvelope;
		if (a.dimensiuniAnvelope != NULL)
			delete[] a.dimensiuniAnvelope;
		a.dimensiuniAnvelope = new int[a.nrAnvelope];
		for (int i = 0; i < a.nrAnvelope; i++)
			in >> a.dimensiuniAnvelope[i];

		return in;
	}

	//exportare in fisier CSV
	void exportCSV(string numeFisierCSV)
	{
		ofstream f(numeFisierCSV, ios::app);
		f << this->marca << ",";
		f << this->model << ",";
		f << this->culoare << ",";
		f << this->nrAnvelope << ",";
		for (int i = 0; i < nrAnvelope; i++)
		{
			f << this->dimensiuniAnvelope[i] << ",";
		}
		f << this->serieSasiu << ",";
		f << endl;
		f.close();
	}

	//importare in fisier CSV
	void importCSV(string numeFisierCSV)
	{
		ifstream f(numeFisierCSV, ios::in);
		if (f.is_open())
		{
			if (this->marca != NULL)
				delete[] this->marca;
			cout << "Marca: ";
			char aux[200];
			f.getline(aux, 199, ',');
			this->marca = new char[strlen(aux) + 1];
			strcpy(this->marca, aux);
			cout << "Model: ";
			f >> this->model;
			cout << "Culoare: ";
			f >> this->culoare;
			cout << "Numar anvelope: ";
			f >> this->nrAnvelope;
			if (this->dimensiuniAnvelope != NULL)
				delete[] this->dimensiuniAnvelope;
			this->dimensiuniAnvelope = new int[this->nrAnvelope];
			for (int i = 0; i < this->nrAnvelope; i++)
				f >> this->dimensiuniAnvelope[i];
		}
		else
			cout << "Fisierul CSV nu exista";
	}



	//destructor
	~Autovehicul()
	{
		delete[] this->marca;
		delete[] this->dimensiuniAnvelope;
	}

};


class Client
{
private:
	static int nrClienti;
	Autovehicul* autovehicul;
	const string CNP;
	char* nume;
	int nrComenzi;
	float* istoricPretComenzi;

public:
	//constructor fara parametri
	Client(Autovehicul* autovehicul) :CNP("Necunoscut")
	{
		nrClienti++;
		this->autovehicul = autovehicul;
		this->nume = new char[strlen("Necunoscut") + 1];
		strcpy(this->nume, "Necunoscut");
		this->nrComenzi = 0;
		this->istoricPretComenzi = nullptr;
	}

	//constrctor cu un parametru
	Client(Autovehicul& autovehicul) :CNP("Necunoscut")
	{
		nrClienti++;
		this->autovehicul = (&autovehicul);
		this->nume = new char[strlen("Necunoscut") + 1];
		strcpy(this->nume, "Necunoscut");
		this->nrComenzi = 0;
		this->istoricPretComenzi = nullptr;
	}

	//constructor cu toti parametri
	Client(Autovehicul& autovehicul, string cnp, const char* nume, int nrComenzi, float* istoricPretComenzi) :CNP(cnp)
	{
		nrClienti++;
		this->autovehicul = (&autovehicul);
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
		this->nrComenzi = nrComenzi;
		this->istoricPretComenzi = new float[this->nrComenzi];
		for (int i = 0; i < this->nrComenzi; i++)
		{
			this->istoricPretComenzi[i] = istoricPretComenzi[i];
		}
	}

	//constructor de copiere
	Client(const Client& c) :CNP(c.CNP)
	{
		nrClienti++;
		this->autovehicul = c.autovehicul;
		this->nume = new char[strlen(c.nume) + 1];
		strcpy(this->nume, c.nume);
		this->nrComenzi = c.nrComenzi;
		this->istoricPretComenzi = new float[c.nrComenzi];
		for (int i = 0; i < c.nrComenzi; i++)
		{
			this->istoricPretComenzi[i] = c.istoricPretComenzi[i];
		}
	}

	//operatorul =
	Client& operator=(const Client& c)
	{
		if (this != &c)
		{
			delete[] this->nume;
			delete[] this->istoricPretComenzi;

			this->autovehicul = c.autovehicul;
			this->nume = new char[strlen(c.nume) + 1];
			strcpy(this->nume, c.nume);
			this->nrComenzi = c.nrComenzi;
			this->istoricPretComenzi = new float[c.nrComenzi];
			for (int i = 0; i < c.nrComenzi; i++)
			{
				this->istoricPretComenzi[i] = c.istoricPretComenzi[i];
			}
		}
		return *this;
	}

	//operator ==
	bool operator==(const Client& c)
	{
		if (nrComenzi == c.nrComenzi && CNP == c.CNP)
		{
			return true;
		}
		else
			return false;
	}

	//getteri
	char* getAutovehicul()
	{
		return autovehicul->getMarca();
	}

	static int getNrClienti()
	{
		return Client::nrClienti;
	}

	string getCNP()
	{
		return this->CNP;
	}

	char* getNumeClient()
	{
		return this->nume;
	}

	int getNrComenzi()
	{
		return this->nrComenzi;
	}

	float* getIstoricPreturi()
	{
		return this->istoricPretComenzi;
	}

	//setteri
	void setNumeClient(const char* nume)
	{
		if (strlen(nume) > 1)
			delete[] this->nume;
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
	}

	void setNrComenzi(int nrComenzi)
	{
		if (nrComenzi > 0)
			this->nrComenzi = nrComenzi;
	}

	void setIstoricPreturi(int nrComenzi, float* istoricPretComenzi)
	{
		if (nrComenzi > 0 && istoricPretComenzi != nullptr)
		{
			delete[] this->istoricPretComenzi;
			this->nrComenzi = nrComenzi;
			this->istoricPretComenzi = new float[nrComenzi];
			for (int i = 0; i < nrComenzi; i++)
				this->istoricPretComenzi[i] = istoricPretComenzi[i];
		}
	}



	//operatorul []
	float& operator[](int index)
	{
		if (index >= 0 && index < this->nrComenzi)
		{
			return this->istoricPretComenzi[index];
		}
	}

	//operatorul !
	bool operator!()
	{
		if (this->nrComenzi > 0)
		{
			return true;
		}
		return false;
	}

	//operator ++ pre incrementare
	Client& operator++()
	{
		float* vn = new float[this->nrComenzi + 1];
		for (int i = 0; i < this->nrComenzi; i++)
		{
			vn[i] = this->istoricPretComenzi[i];
		}
		vn[this->nrComenzi] = 0;
		delete[] this->istoricPretComenzi;

		this->istoricPretComenzi = vn;
		this->nrComenzi++;

		return *this;
	}

	//operator ++ post incrementare
	Client operator++(int)
	{
		Client rez = *this;

		float* vn = new float[this->nrComenzi + 1];
		for (int i = 0; i < this->nrComenzi; i++)
		{
			vn[i] = this->istoricPretComenzi[i];
		}
		vn[this->nrComenzi] = 0;
		delete[] this->istoricPretComenzi;

		this->istoricPretComenzi = vn;
		this->nrComenzi++;

		return rez;
	}

	//operator >
	bool operator>(Client c)
	{
		return this->nrComenzi > c.nrComenzi;
	}

	//operator cast
	explicit operator int()
	{
		return this->nrComenzi;
	}

	//functie calculare cheltuieli client
	float calculareCheltuieli()
	{
		float m = 0;
		if (this->nrComenzi > 0)
		{
			for (int i = 0; i < this->nrComenzi; i++)
			{
				m += this->istoricPretComenzi[i];
			}
		}
		return m;
	}

	//operatorul <<
	friend ostream& operator<<(ostream& out, Client& c)
	{
		out << "\n---------------------------------------";
		out << "\nNume client: " << c.nume;
		out << "\nCNP client: " << c.CNP;
		out << "\nAutovehiculul: " << c.getAutovehicul();
		out << "\nNumar comenzi: " << c.nrComenzi;
		out << "\nIstoricul platilor: ";
		for (int i = 0; i < c.nrComenzi; i++) {
			out << c.istoricPretComenzi[i] << " ";
		}
		out << "\n---------------------------------------";

		return out;
	}

	//operatorul >>
	friend istream& operator>>(istream& in, Client& c)
	{
		delete[] c.nume;
		delete[] c.istoricPretComenzi;

		cout << "\nIntroduceti numele clientului: ";
		char auxnume[100];
		in >> auxnume;
		c.nume = new char[strlen(auxnume) + 1];
		strcpy(c.nume, auxnume);
		cout << "\nIntroduceti autovehiculul clientului: ";
		char auxauto[100];
		in >> auxauto;
		c.autovehicul->setMarca(auxauto);
		cout << "\nIntroduceti numarul de comenzi: ";
		in >> c.nrComenzi;
		c.istoricPretComenzi = new float[c.nrComenzi];
		for (int i = 0; i < c.nrComenzi; i++)
		{
			cout << "Pretul comenzii " << i + 1 << ": ";
			in >> c.istoricPretComenzi[i];
		}
		return in;
	}

	//functia de afisare
	void afisare()
	{
		cout << "\n-----------------------------";
		cout << "\nNumar clienti: " << this->nrClienti;
		cout << "\nNume: " << this->nume;
		cout << "\nCNP: " << this->CNP;
		cout << "\nAutovehicul: " << this->getAutovehicul();
		cout << "\nNumarul de comenzi: " << this->nrComenzi;
		cout << "\nIstoric pret comenzi: ";
		for (int i = 0; i < this->nrComenzi; i++)
			cout << this->istoricPretComenzi[i] << " ";
		cout << "\n-----------------------------";
	}



	//serializare 
	void serializare() {
		ofstream f("client.bin", ios::binary);
		f.write((char*)&nume, sizeof(nume));
		f.write((char*)&nrComenzi, sizeof(nrComenzi));
		if (istoricPretComenzi != NULL) {
			for (int i = 0; i < nrComenzi; i++) {
				f.write((char*)&istoricPretComenzi[i], sizeof(istoricPretComenzi[i]));
			}
		}
		f.close();
	}

	//deserializare
	void deserializare() {
		ifstream f("client.bin", ios::binary);
		int length = 0;
		f.read((char*)&length, sizeof(length));
		char* buffer = new char[length + 1];
		f.read(buffer, length + 1);
		delete[] nume;
		nume = new char[length + 1];
		strcpy_s(nume, length + 1, buffer);
		delete[] buffer;
		f.read((char*)&nrComenzi, sizeof(nrComenzi));
		delete[] istoricPretComenzi;
		istoricPretComenzi = new float[nrComenzi];
		if (istoricPretComenzi != NULL) {
			for (int i = 0; i < nrComenzi; i++) {
				f.read((char*)&istoricPretComenzi[i], sizeof(istoricPretComenzi[i]));
			}
		}
		f.close();
	}

	//citire din fisier txt
	friend ofstream& operator<<(ofstream& out, Client& c)
	{
		out << "\n---------------------------------------";
		out << "\nAutovehiculul: " << c.getAutovehicul();
		out << "\nCNP client: " << c.CNP;
		out << "\nNume client: " << c.nume;
		out << "\nNumar comenzi: " << c.nrComenzi;
		out << "\nIstoricul preturilor: ";
		for (int i = 0; i < c.nrComenzi; i++)
			out << c.istoricPretComenzi[i] << " ";
		out << "\n---------------------------------------";

		return out;
	}

	//scriere fisier txt
	friend ifstream& operator>>(ifstream& in, Client& c)
	{
		in >> c.getAutovehicul();
		if (c.nume != NULL)
			delete[] c.nume;
		char aux[200];
		in.getline(aux, 199);
		c.nume = new char[strlen(aux) + 1];
		strcpy(c.nume, aux);
		in >> c.nrComenzi;
		if (c.istoricPretComenzi != NULL)
			delete[] c.istoricPretComenzi;
		c.istoricPretComenzi = new float[c.nrComenzi];
		for (int i = 0; i < c.nrComenzi; i++)
			in >> c.istoricPretComenzi[i];

		return in;
	}

	//exportare in fisier CSV
	void exportCSV(string numeFisierCSV)
	{
		ofstream f(numeFisierCSV, ios::app);
		f << this->getAutovehicul() << ",";
		f << this->CNP << ",";
		f << this->nume << ",";
		f << this->nrComenzi << ",";
		for (int i = 0; i < nrComenzi; i++)
		{
			f << this->istoricPretComenzi[i] << ",";
		}
		f << endl;
		f.close();
	}

	//importare din fisier CSV
	void importCSV(string numeFisierCSV)
	{
		ifstream f(numeFisierCSV, ios::in);
		if (f.is_open())
		{
			cout << "Autovehicul: ";
			f >> this->getAutovehicul();
			if (this->nume != NULL)
				delete[] this->nume;
			cout << "Nume client: ";
			char aux[200];
			f.getline(aux, 199, ',');
			this->nume = new char[strlen(aux) + 1];
			strcpy(this->nume, aux);
			cout << "Numar comenzi: ";
			f >> this->nrComenzi;
			if (this->istoricPretComenzi != NULL)
				delete[] this->istoricPretComenzi;
			this->istoricPretComenzi = new float[this->nrComenzi];
			for (int i = 0; i < this->nrComenzi; i++)
				f >> this->istoricPretComenzi[i];
		}
		else
			cout << "Fisierul CSV nu exista";
	}

	//destructorul
	~Client()
	{
		delete[] this->nume;
		delete[] this->istoricPretComenzi;
	}


};
int Client::nrClienti = 0;


class Sediu
{
private:
	Angajat* angajat;
	static int nrSedii;
	char* locatie;
	int nrMontari;
	int* durataMinute;
	string tura;

public:
	//constructor fara parametri
	Sediu(Angajat* angajat)
	{
		nrSedii++;
		this->angajat = angajat;
		this->locatie = new char[strlen("Necunoscuta") + 1];
		strcpy(this->locatie, "Necunoscuta");
		this->nrMontari = 0;
		this->durataMinute = nullptr;
		this->tura = "Necunoscuta";
	}


	//constructor cu un parametru
	Sediu(Angajat& angajat)
	{
		nrSedii++;
		this->angajat = (&angajat);
		this->locatie = new char[strlen("Necunoscuta") + 1];
		strcpy(this->locatie, "Necunoscuta");
		this->nrMontari = 0;
		this->durataMinute = nullptr;
		this->tura = "Necunoscuta";
	}

	//constructor cu toti parametri
	Sediu(Angajat& angajat, const char* locatie, int nrMontari, int* durataMinute, string tura)
	{
		nrSedii++;
		this->angajat = (&angajat);
		this->locatie = new char[strlen(locatie) + 1];
		strcpy(this->locatie, locatie);
		this->nrMontari = nrMontari;
		this->durataMinute = new int[this->nrMontari];
		for (int i = 0; i < this->nrMontari; i++)
		{
			this->durataMinute[i] = durataMinute[i];
		}
		this->tura = tura;
	}

	//constructor de copiere
	Sediu(const Sediu& s)
	{
		nrSedii++;
		this->angajat = s.angajat;
		this->locatie = new char[strlen(s.locatie) + 1];
		strcpy(this->locatie, s.locatie);
		this->nrMontari = s.nrMontari;
		this->durataMinute = new int[s.nrMontari];
		for (int i = 0; i < s.nrMontari; i++)
		{
			this->durataMinute[i] = s.durataMinute[i];
		}
		this->tura = s.tura;
	}

	//operatorul =
	Sediu& operator=(const Sediu& s)
	{
		if (this != &s)
		{
			delete[] this->locatie;
			delete[] this->durataMinute;

			this->angajat = s.angajat;
			this->locatie = new char[strlen(s.locatie) + 1];
			strcpy(this->locatie, s.locatie);
			this->nrMontari = s.nrMontari;
			this->durataMinute = new int[s.nrMontari];
			for (int i = 0; i < s.nrMontari; i++)
			{
				this->durataMinute[i] = s.durataMinute[i];
			}
			this->tura = s.tura;
		}
		return *this;
	}

	//operator ==
	bool operator==(const Sediu& s)
	{
		if (tura == s.tura && nrMontari == s.nrMontari)
		{
			return true;
		}
		else
			return false;
	}

	//getteri
	char* getAngajat()
	{
		return angajat->getNume();
	}

	static int getNrSedii()
	{
		return Sediu::nrSedii;
	}

	char* getLocatie()
	{
		return this->locatie;
	}

	int getNrMontari()
	{
		return this->nrMontari;
	}

	int* getDurataMinute()
	{
		return this->durataMinute;
	}

	string getTura()
	{
		return this->tura;
	}

	//setteri

	void setLocatie(const char* locatie)
	{
		if (strlen(locatie) > 1)
		{
			delete[] this->locatie;
			this->locatie = new char[strlen(locatie) + 1];
			strcpy(this->locatie, locatie);
		}
	}

	void setNrMontari(int nrMontari)
	{
		if (nrMontari > 0)
		{
			this->nrMontari = nrMontari;
		}
	}

	void setDurataMinute(int nrMontari, int* durataMinute)
	{
		if (nrMontari > 0 && durataMinute != nullptr)
		{
			delete[] this->durataMinute;
			this->nrMontari = nrMontari;
			this->durataMinute = new int[nrMontari];
			for (int i = 0; i < nrMontari; i++)
			{
				this->durataMinute[i] = durataMinute[i];
			}
		}
	}

	void setTura(string tura)
	{
		if (tura.length() > 0)
		{
			this->tura = tura;
		}
	}

	//operatorul []
	int& operator[](int index)
	{
		if (index >= 0 && index < this->nrMontari)
		{
			return this->durataMinute[index];
		}
	}

	//operatorul !
	bool operator!()
	{
		if (this->nrMontari > 0)
		{
			return true;
		}
		return false;
	}

	//operator ++ pre incrementare
	Sediu& operator++()
	{
		int* vn = new int[this->nrMontari + 1];
		for (int i = 0; i < this->nrMontari; i++)
		{
			vn[i] = this->durataMinute[i];
		}
		vn[this->nrMontari] = 0;
		delete[] this->durataMinute;

		this->durataMinute = vn;
		this->nrMontari++;

		return *this;
	}

	//operator ++ post incrementare
	Sediu operator++(int)
	{
		Sediu rez = *this;

		int* vn = new int[this->nrMontari + 1];
		for (int i = 0; i < this->nrMontari; i++)
		{
			vn[i] = this->durataMinute[i];
		}
		vn[this->nrMontari] = 0;
		delete[] this->durataMinute;

		this->durataMinute = vn;
		this->nrMontari++;

		return rez;
	}

	//operator >
	bool operator>(Sediu s)
	{
		return this->nrMontari > s.nrMontari;
	}

	//operator cast
	explicit operator int()
	{
		return this->nrMontari;
	}

	//functie de calculare durata montari
	int durata()
	{
		int d = 0;
		if (this->nrMontari > 0)
		{
			for (int i = 0; i < this->nrMontari; i++)
			{
				d += this->durataMinute[i];
			}
		}
		return d;
	}

	//operator <<
	friend ostream& operator<<(ostream& out, Sediu& s)
	{
		out << "\n---------------------------------------";
		out << "\nAngajatul: " << s.getAngajat();
		out << "\nLocatie sediu: " << s.locatie;
		out << "\nNumar montari: " << s.nrMontari;
		out << "\nDurata montarilor: ";
		for (int i = 0; i < s.nrMontari; i++) {
			out << s.durataMinute[i] << " ";
		}
		out << "\nTura in care lucreaza angajatul: " << s.tura;
		out << "\n---------------------------------------";

		return out;
	}

	//operator >>
	friend istream& operator>>(istream& in, Sediu& s)
	{
		delete[] s.locatie;
		delete[] s.durataMinute;

		cout << "\nIntroduceti numele angajatului: ";
		char auxnume[100];
		in >> auxnume;
		s.angajat->setNume(auxnume);
		cout << "\nIntroduceti locatia sediului: ";
		char auxloc[100];
		in >> auxloc;
		s.locatie = new char[strlen(auxloc) + 1];
		strcpy(s.locatie, auxloc);
		cout << "\nIntroduceti numarul de montari: ";
		in >> s.nrMontari;
		s.durataMinute = new int[s.nrMontari];
		for (int i = 0; i < s.nrMontari; i++)
		{
			cout << "Durata montarii " << i + 1 << ": ";
			in >> s.durataMinute[i];
		}
		cout << "\nIntroduceti tura angajatului: ";
		in >> s.tura;

		return in;
	}

	//functia de afisare
	void afisare()
	{
		cout << "\n-----------------------------";
		cout << "\nAngajatul: " << this->getAngajat();
		cout << "\nLocatie: " << this->locatie;
		cout << "\nNumarul de montari: " << this->nrMontari;
		cout << "\nDimensiuni anvelope: ";
		for (int i = 0; i < this->nrMontari; i++)
			cout << this->durataMinute[i] << " ";
		cout << "\nTura angajatului: " << this->tura;
		cout << "\n-----------------------------";
	}

	//serializare
	void serializare()
	{
		ofstream f("sediu.bin", ios::binary);
		f.write((char*)&locatie, sizeof(locatie));
		f.write((char*)&nrMontari, sizeof(nrMontari));
		if (durataMinute != NULL) {
			for (int i = 0; i < nrMontari; i++) {
				f.write((char*)&durataMinute[i], sizeof(durataMinute[i]));
			}
		}
		f.write((char*)&tura, sizeof(tura));
		f.close();
	}

	//deserializare
	void deserializare()
	{
		ifstream f("sediu.bin", ios::binary);
		int length = 0;
		f.read((char*)&length, sizeof(length));
		char* buffer = new char[length + 1];
		f.read(buffer, length + 1);
		delete[] locatie;
		locatie = new char[length + 1];
		strcpy_s(locatie, length + 1, buffer);
		delete[] buffer;
		f.read((char*)&nrMontari, sizeof(nrMontari));
		delete[] durataMinute;
		durataMinute = new int[nrMontari];
		if (durataMinute != NULL) {
			for (int i = 0; i < nrMontari; i++)
			{
				f.read((char*)&durataMinute[i], sizeof(durataMinute[i]));
			}
		}
		f.read((char*)&tura, sizeof(tura));
		f.close();
	}


	//citire din fisier txt
	friend ofstream& operator<<(ofstream& out, Sediu& s)
	{
		out << "\n---------------------------------------";
		out << "\nAngajat: " << s.getAngajat();
		out << "\nLocatia sediului: " << s.locatie;
		out << "\nNumar montari: " << s.nrMontari;
		out << "\nDurata montarilor: ";
		for (int i = 0; i < s.nrMontari; i++)
			out << s.durataMinute[i] << " ";
		out << "\nTura angajatului: " << s.tura;
		out << "\n---------------------------------------";

		return out;
	}

	//scriere fisier txt
	friend ifstream& operator>>(ifstream& in, Sediu& s)
	{
		in >> s.getAngajat();
		if (s.locatie != NULL)
			delete[] s.locatie;
		char aux[200];
		in.getline(aux, 199);
		s.locatie = new char[strlen(aux) + 1];
		strcpy(s.locatie, aux);
		in >> s.nrMontari;
		if (s.durataMinute != NULL)
			delete[] s.durataMinute;
		s.durataMinute = new int[s.nrMontari];
		for (int i = 0; i < s.nrMontari; i++)
			in >> s.durataMinute[i];
		in >> s.tura;

		return in;
	}


	//exportare in fisier CSV
	void exportCSV(string numeFisierCSV)
	{
		ofstream f(numeFisierCSV, ios::app);
		f << this->getAngajat() << ",";
		f << this->locatie << ",";
		f << this->nrMontari << ",";
		for (int i = 0; i < nrMontari; i++)
		{
			f << this->durataMinute[i] << ",";
		}
		f << this->tura << ",";
		f << endl;
		f.close();
	}

	//importare din fisier CSV
	void importCSV(string numeFisierCSV)
	{
		ifstream f(numeFisierCSV, ios::in);
		if (f.is_open())
		{
			cout << "Angajatul: ";
			f >> this->getAngajat();
			if (this->locatie != NULL)
				delete[] this->locatie;
			cout << "Locatia sediului: ";
			char aux[200];
			f.getline(aux, 199, ',');
			this->locatie = new char[strlen(aux) + 1];
			strcpy(this->locatie, aux);
			cout << "Numar montari: ";
			f >> this->nrMontari;
			if (this->durataMinute != NULL)
				delete[] this->durataMinute;
			this->durataMinute = new int[this->nrMontari];
			for (int i = 0; i < this->nrMontari; i++)
				f >> this->durataMinute[i];
		}
		else
			cout << "Fisierul CSV nu exista";
	}


	//destructorul
	~Sediu()
	{
		delete[] this->locatie;
		delete[] this->durataMinute;
	}

};
int Sediu::nrSedii = 0;

class Manager :public Angajat
{
private:
	string departament;
	string proiect;
	int nrAngajatiSupervizati;

public:
	Manager(string departament, string proiect, int nrAngajatiSupervizati,int idAngajat, const char* nume,float salariu, int aniVechime, int nrZileLucrate, int* zileLucrate):Angajat(idAngajat,nume, salariu, aniVechime,nrZileLucrate,zileLucrate)
	{
		this->departament = departament;
		this->proiect = proiect;
		this->nrAngajatiSupervizati = nrAngajatiSupervizati;

	}

	void afisare()
	{
		cout << "\n---------------------------------------";
		cout << "\nID angajat: " << this->idAngajat;
		cout << "\nNume angajat: " << this->nume;
		cout << "\nSalariu angajat: " << this->salariu;
		cout << "\nAni vechime angajat: " << this->aniVechime;
		cout << "\nNumarul zilelor lucrate: " << this->nrZileLucrate;
		cout << "\nZile lucrate: ";
		for (int i = 0; i < this->nrZileLucrate; i++)
			cout << this->zileLucrate[i] << " ";
		cout << "\nDepartament: " << this->departament;
		cout << "\nProiect: " << this->proiect;
		cout << "\nAngajati supervizati: " << this->nrAngajatiSupervizati;
		cout << "\n---------------------------------------";
	}
};

void Meniu(Client& c, Sediu& s)
{
	while (true)
	{
		cout << "Meniu: " << endl;
		cout << "1.Sa se afiseze cheltuielile primului client" << endl;
		cout << "2.Sa se afiseze durata totala a montarilor pentru cel de al 2-lea sediu" << endl;
		cout << "3.Iesire" << endl;

		int optiune;
		cin >> optiune;

		switch (optiune)
		{
		case 1:
			cout << c.calculareCheltuieli() << endl;
			break;

		case 2:
			cout << s.durata() << endl;
			break;

		case 3:
			return;

		default:
			cout << "Optiune invalida" << endl;
		}
	}

}


int main() {
	//cout<<"Testare clasa Anvelope"<<endl;
	//
	//	//constructor cu un parametru
	//	Anvelope a1("Michelin");
	//	a1.afisare();
	//
	//	//constructor cu toti parametri
	//	float preturi[] = { 1000,1250,1300,1115 };
	//	Anvelope a2("iarna", 15, "Pirelli", 4, preturi);
	//	a2.afisare();
	//
	//	//constructor de copiere
	//	Anvelope a3(a2);
	//	a3.afisare();
	//
	//	//operator =
	//	Anvelope a4 = a3;
	//	a4.afisare();
	//
	//	//operator ==
	//	if (a3 == a4)
	//		cout << "\na3==a4" << endl;
	//	else
	//		cout << "\na3!=a4" << endl;
	//
	//	//operator index []
	//	cout << a2[3] << endl;
	//
	//	//operator !
	//	if (!a3)
	//		cout << "\nAdevarat" << endl;
	//	else
	//		cout << "\nFals" << endl;
	//
	//	//operatorul ++ pre
	//	++a2;
	//	cout << a2;
	//
	//	//operatorul ++ post
	//	a2++;
	//	cout << a2;
	//
	//	//operatorul >
	//	if (a2 > a1)
	//		cout << "\nDimensiunea a2 este > decat dimensiuea a1" << endl;
	//	else
	//		cout << "\nInvers" << endl;
	//
	//	//operatorul cast
	//	cout << "Dimensiunea anvelopei a2 este: " << (int)a2 << endl;
	//
	//	//getteri si setteri
	//	cout << a1.getProducator() << endl;
	//	a1.setProducator("pirelli");
	//	cout << a1.getProducator() << endl;
	//
	//
	//	//operator >>
	//	cin >> a4;
	//
	//	//operator <<
	//	cout << a4;
	//
	//
	//
	//
	//
	//
	//
	//	cout<<"Testare clasa Angajat"<<endl;
	//
	//	//constructor cu un parametru
	//	Angajat aj1("Marcel");
	//	aj1.afisare();
	//
	//	
	//
	//	//constructor cu toti parametri
	/*	int zile[] = { 1, 3, 4, 5 };
		Angajat aj2(1, "Ionel", 2750.57, 5, 4, zile);
		aj2.afisare();*/
		//
		//	//constructor de copiere
		//	Angajat aj3(aj2);
		//	aj3.afisare();
		//
		//	//operator =
		//	Angajat aj4 = aj3;
		//	aj4.afisare();
		//
		//	//operator ==
		//	if (aj3 == aj4)
		//		cout << "\naj3==aj4" << endl;
		//	else
		//		cout << "\naj3!=aj4" << endl;
		//
		//	//operator index []
		//	cout << aj2[3] << endl;
		//
		//	//operator !
		//	if (!aj3)
		//		cout << "\nAdevarat" << endl;
		//	else
		//		cout << "\nFals" << endl;
		//
		//	//operatorul ++ pre
		//	++aj2;
		//	cout << aj2;
		//
		//	//operatorul ++ post
		//	aj2++;
		//	cout << aj2;
		//
		//	//operatorul >
		//	if (aj2 > aj1)
		//		cout << "\nSalariu angajatului aj2 este > decat salariul lui aj1" << endl;
		//	else
		//		cout << "\nInvers" << endl;
		//
		//	//operatorul index []
		//	cout << aj2[3] << endl;
		//
		//	//operatorul cast
		//	cout << "Vechimea lui aj2 este: " << (int)aj2 << " ani" << endl;
		//
		//	//getteri si setteri
		//	cout << aj2.getNume() << endl;
		//	aj2.setNume("Gigel");
		//	cout << aj2.getNume() << endl;
		//
		//	//operator >>
		//	cin >> aj4;
		//
		//	//operator <<
		//	cout << aj4;
		//
		//
		//
		//
		//
		//
		//
	//	cout<<"Testare clasa Autovehicul"<<endl;
		//	//constructor cu un parametru
		//	Autovehicul av1("SCBEWXS1993NJ1158");
		//	av1.afisare();
		//
			////constructor cu toti parametri
			//int dim[] = { 15, 16, 18,17 };
			//Autovehicul av2("ZARYB2WJZAN584057", "Opel", "Astra", "Rosu", 4, dim);
			//av2.afisare();

			////constructor de copiere
			//Autovehicul av3(av2);
			//av3.afisare();
		//
		//	//operatorul =
		//	Autovehicul av4 = av3;
		//	av4.afisare();
		//
		//	//operator ==
		//	if (av3 == av4)
		//		cout << "\nav3==av4" << endl;
		//	else
		//		cout << "\nav3!=av4" << endl;
		//
		//	//getteri si setteri
		//	cout << av2.getCuloare() << endl;
		//	av2.setCuloare("Albastru");
		//	cout << av2.getCuloare() << endl;
		//
		//	//operatorul index
		//	cout << av2[2] << endl;
		//
		//	//operator !
		//	if (!av3)
		//		cout << "\nAdevarat" << endl;
		//	else
		//		cout << "\nFals" << endl;
		//
		//	//operatorul ++ pre
		//	++av2;
		//	cout << av2;
		//
		//	//operatorul ++ post
		//	av2++;
		//	cout << av2;
		//
		//	//operatorul>
		//	if (av2 > av1)
		//		cout << "\nNumarul de anvelope al masinii av2 > decat av1" << endl;
		//	else
		//		cout << "\nInvers" << endl;
		//
		//	//operatorul cast
		//	cout << "\nNumarul de anvelope al masinii av2 este: " << (int)av2 << endl;
		//
		//	//operatorul >>
		//	cin >> av3;
		//
		//	//operatorul << 
		//	cout << av3;
		//
		//
		//
		//
		//
		//	cout<<"Testare clasa Client"<<endl;
		//	constructor cu un parametru
		//	Client c1(av3);
		//	c1.afisare();
		//
			//constructor cu toti parametri
		/*	float pret[] = { 250.6,345.5,903.4 };
			Client c2(av3, "1234567890123", "maria", 3, pret);
			c2.afisare();*/
			//
			//	//constructor de copiere
			//	Client c3(c2);
			//	c3.afisare();
			//
			//	//operator =
			//	Client c4 = c3;
			//	c4.afisare();
			//
			//	//operator ==
			//	if (c3 == c4)
			//		cout << "\nc3==c4" << endl;
			//	else
			//		cout << "\nc3!=c4" << endl;
			//
			//	//getteri si setteri
			//	cout << c2.getNumeClient() << endl;
			//	c2.setNumeClient("Mihaela");
			//	cout << c2.getNumeClient() << endl;
			//
			//	//operatorul index
			//	cout << c2[2] << endl;
			//
			//	//operator !
			//	if (!c3)
			//		cout << "\nAdevarat" << endl;
			//	else
			//		cout << "\nFals" << endl;
			//
			//	//operatorul ++ pre
			//	++c2;
			//	cout << c2;
			//
			//	//operatorul ++ post
			//	c2++;
			//	cout << c2;
			//
			//	//operatorul>
			//	if (c2 > c1)
			//		cout << "\nNumarul de comenzi al clientului c2 > decat c1" << endl;
			//	else
			//		cout << "\nInvers" << endl;
			//
			//	//operatorul cast
			//	cout << "\nNumarul de comenzi al clientului c2 este: " << (int)c2 << endl;
			//
			//	//operatorul >>
			//	cin >> c4;
			//
			//	//operatorul <<
			//	cout << c4 << endl;
			//
			//
			//	//functie de prelucrare
			//	cout << c2.calculareCheltuieli();
			//
			//
			//
			//
			//
			//	cout<<"Testare clasa Sediu"<<endl;
			//	constructor cu un parametru
			//	Sediu s1(aj2);
			//	s1.afisare();
			//
			//	constructor cu toti parametri
				//int durata[] = { 37,45,60 };
				//Sediu s2(aj2, "Bucuresti", 3, durata, "de la 8 00 la 16 00");
				//s2.afisare();
			//
			//	constructor de copiere
			//	Sediu s3(s2);
			//	s3.afisare();
			//
			//	//operator =
			//	Sediu s4 = s3;
			//	c4.afisare();
			//
			//	operator ==
			//	if (s3 == s4)
			//		cout << "\ns3==s4" << endl;
			//	else
			//		cout << "\ns3!=s4" << endl;
			//
			//	//getteri si setteri
			//	cout << s2.getLocatie() << endl;
			//	s2.setLocatie("Ploiesti");
			//	cout << s2.getLocatie() << endl;
			//
			//	//operatorul index
			//	cout << s2[2] << endl;
			//
			//	//operator !
			//	if (!s3)
			//		cout << "\nAdevarat" << endl;
			//	else
			//		cout << "\nFals" << endl;
			//
			//	//operatorul ++ pre
			//	++s2;
			//	cout << s2;
			//
			//	//operatorul ++ post
			//	s2++;
			//	cout << s2;
			//
			//	//operatorul>
			//	if (s2 > s1)
			//		cout << "\nNumarul de montari al sediului s2 > decat s1" << endl;
			//	else
			//		cout << "\nInvers" << endl;
			//
			//	//operatorul cast
			//	cout << "\nNumarul de montari al sediului s2 este: " << (int)s2 << endl;
			//
			//	//operator >>
			//	cin >> s4;
			//
			//	//operator<<
			//	cout << s4 << endl;
			//
			//	//functie calculare durata totala montari
			//	cout << s2.durata();


			int zile[] = { 1, 3, 4, 5 };
			Angajat angajat(1, "John Smith", 2500.50, 5, 4, zile);
			//citire din fisier
				ofstream gi("ang1.txt", ios::out);
				gi << angajat << endl;
				gi.close();
		
			//scriere in fisier
			cout << angajat;
			ifstream fi("ang1.txt", ios::in);
			//serializare
			angajat.serializare();
			// deserializare
			angajat.deserializare();
			//export fisier csv
			angajat.exportCSV("fisierCSV.csv");
			//import fisier csv
			Angajat aj6;
			cout << aj6  << endl;
			aj6.importCSV("fisierCSV2.csv");


		int nrzile[] = {1,3,4,5};
		Manager m1("marketing", "anvelope primavara", 11,1234,"Ion",2500,5,4,nrzile);
		m1.afisare();

			Meniu(c2,s2);


	return 0;
}
