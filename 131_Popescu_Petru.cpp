#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <utility>

using namespace std;

#pragma region DateAjutatoare
pair <string, string> listaDefectiuniPosibileAuto[15] = {make_pair("",""), make_pair("placute uzate fata", "frane"), make_pair("placute uzate spate", "frane"), make_pair("discuri uzate", "frane"),
                                                       make_pair("defectiune capitala", "frane"), make_pair("nivel ulei scazut", "motor"), make_pair("carburator murdar", "motor"),
                                                       make_pair("motor topit" , "motor"), make_pair("roata stramba" , "directie"), make_pair("defectiune capitala", "directie"),
                                                       make_pair("vehiculul arde ulei", "noxe"), make_pair("vehiculul este anterior anului 2000", "noxe"), make_pair("caroserie corodata de rugina", "caroserie"),
                                                       make_pair("caroserie stramba", "caroserie"), make_pair("caroserie zgariata", "caroserie")};

pair <string, string> listaDefectiuniPosibileMoto[11] = {make_pair("",""), make_pair("placute uzate fata", "frane"), make_pair("placute uzate spate", "frane"), make_pair("discuri uzate", "frane"),
                                                       make_pair("defectiune capitala", "frane"), make_pair("motor topit" , "motor"), make_pair("ghidon stramb" , "directie"),
                                                       make_pair("roata stramba" , "directie"), make_pair("defectiune capitala", "directie"), make_pair("vehiculul arde ulei", "noxe"),
                                                       make_pair("vehiculul este anterior anului 2000", "noxe")};

pair <string, string> listaDefectiuniPosibileBicicleta[6] = {make_pair("",""), make_pair("lant tocit", "frane"), make_pair("lant lipsa", "frane"), make_pair("ghidon stramb" , "directie"),
                                                            make_pair("roata stramba" , "directie"), make_pair("defectiune capitala", "directie")};

pair <string, int> MaterialeAuto[15] = {make_pair("", 0), make_pair("placuta fata", 1), make_pair("placuta spate", 2), make_pair("disc", 3), make_pair("", 0),
                                      make_pair("ulei", 4), make_pair("solutie carburator", 5), make_pair("ulei", 4), make_pair("roata", 6), make_pair("", 0),
                                      make_pair("ulei", 4), make_pair("vinieta eco", 7), make_pair("vopsea", 8), make_pair("", 0), make_pair("polish", 9)};

pair <string, int> MaterialeMoto[11] = {make_pair("", 0), make_pair("placuta fata", 1), make_pair("placuta spate", 2), make_pair("disc", 3), make_pair("", 0),
                                      make_pair("ulei", 4), make_pair("ghidon", 10), make_pair("roata motocicleta", 11), make_pair("", 0), make_pair("ulei", 4), make_pair("vinieta eco", 7)};

pair <string, int> MaterialeBicicleta[6] = {make_pair("", 0), make_pair("lant", 12), make_pair("lant",12), make_pair("ghidon bicicleta", 13), make_pair("roata bicicleta", 14), make_pair("", 0)};

int generatorAuto[15] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
int generatorMoto[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int generatorBicicleta[6] = {0, 1, 2, 3, 4, 5,};
int materialeDisponibile[15];
const int preturi[15] = {0, 70, 70, 130, 40, 40, 400, 100, 80, 40, 150, 250, 50, 50, 100};
const int cantitateMaxima[15] = {1, 2, 2, 2, 5, 3, 4, 1, 3, 2, 1, 2, 1, 1, 2};
const int nrDefectiuniAutoInit = 14, nrDefectiuniMotoInit = 10, nrDefectiuniBicicletaInit = 5;

int nrDefectiuniAuto = 14, nrDefectiuniMoto = 10, nrDefectiuniBicicleta = 5;
const int pretSurub = 2, pretOraUmana = 35;

#pragma endregion


#pragma region Defectiune
class Defectiune
{
private:
    string piesaAfectata, tipDefectiune, materialNecesar;
    int cantitate, pret, tipVehicul, suruburi, oreUmane; //tip vehicul: -1 sau -2 -nu se mai poate repara, 1-auto, 2-moto, 3-bicicleta
public:

    void set_piesaAfectata(string s);
    void set_tipDefectiune(string s);
    void set_materialNecesar(string s);
    void set_cantitate(int x);
    void set_pret(int x);
    void set_tipVehicul(int x);

    string get_piesaAfectata();
    string get_tipDefectiune();
    int get_cantitate();
    int get_pret();
    int get_tipVehicul();
    string get_materialNecesar();

    //Defectiune();
    //Defectiune( const Defectiune &defectiune);
    Defectiune generareDefectiune(Defectiune D, int x);
    //~Defectiune();
    friend istream& operator>>(istream &in, Defectiune &defectiune);
    friend ostream& operator<<(ostream &out, Defectiune &defectiune);
};

#pragma region Set&GetDefectiune

void Defectiune :: set_piesaAfectata(string piesaAfectata)
{
    this->piesaAfectata = piesaAfectata;
}

void Defectiune :: set_tipDefectiune(string tipDefectiune)
{
    this->tipDefectiune = tipDefectiune;
}

void Defectiune :: set_materialNecesar(string s)
{
    this->materialNecesar = materialNecesar;
}

void Defectiune :: set_cantitate(int cantitate)
{
    this->cantitate = cantitate;
}

void Defectiune :: set_pret(int pret)
{
    this->pret = pret;
}

void Defectiune :: set_tipVehicul(int tipVehicul)
{
    this->tipVehicul = tipVehicul;
}

string Defectiune :: get_piesaAfectata()
{
    return piesaAfectata;
}

string Defectiune :: get_tipDefectiune()
{
    return tipDefectiune;
}

int Defectiune :: get_cantitate()
{
    return cantitate;
}

int Defectiune :: get_pret()
{
    return pret;
}

int Defectiune :: get_tipVehicul()
{
    return tipVehicul;
}

string Defectiune :: get_materialNecesar()
{
    return materialNecesar;
}
#pragma endregion

/*Defectiune :: Defectiune(const Defectiune &defectiune)
{
    this->piesaAfectata = defectiune.piesaAfectata;
    this->tipDefectiune = defectiune.tipDefectiune;
    this->cantitate = defectiune.cantitate;
    this->pret = defectiune.pret;
    this->tipVehicul = defectiune.tipVehicul;
}*/

Defectiune Defectiune :: generareDefectiune(Defectiune D, int x)
{

    D.tipVehicul = x;
    int xr, r;
    srand(time(NULL));
    switch(D.tipVehicul)
    {
        case 1:
            xr = rand() % nrDefectiuniAuto + 1;
            r = generatorAuto[xr];
            D.piesaAfectata = listaDefectiuniPosibileAuto[r].second;
            D.tipDefectiune = listaDefectiuniPosibileAuto[r].first;
            if(D.tipDefectiune == "defectiune capitala")
            {
                break;
            }
            D.materialNecesar = MaterialeAuto[r].first;
            D.pret = preturi[MaterialeAuto[r].second];
            D.cantitate = rand() % cantitateMaxima[MaterialeAuto[r].second] + 1;
            D.pret *= D.cantitate;
            if(materialeDisponibile[MaterialeAuto[r].second] - D.cantitate < 0)
            {
                D.tipDefectiune = "lipsa materiale";
                break;
            }
            materialeDisponibile[MaterialeAuto[r].second] -= D.cantitate;
            D.suruburi = rand() % 10 + 5;
            D. oreUmane = rand() % 4 + 1;
            D.pret += pretSurub*D.suruburi + pretOraUmana * D.oreUmane;
            swap(generatorAuto[xr],generatorAuto[nrDefectiuniAuto--]);
            break;
        case 2:
            xr = rand() % nrDefectiuniMoto + 1;
            r = generatorMoto[xr];
            D.piesaAfectata = listaDefectiuniPosibileMoto[r].second;
            D.tipDefectiune = listaDefectiuniPosibileMoto[r].first;
            if(D.tipDefectiune == "defectiune capitala")
            {
                break;
            }
            D.materialNecesar = MaterialeMoto[r].first;
            D.pret = preturi[MaterialeMoto[r].second];
            D.cantitate = rand() % cantitateMaxima[MaterialeMoto[r].second] + 1;
            D.pret *= D.cantitate;
            if(materialeDisponibile[MaterialeMoto[r].second] - D.cantitate < 0)
            {
                D.tipDefectiune = "lipsa materiale";
                break;
            }
            materialeDisponibile[MaterialeMoto[r].second] -= D.cantitate;
            D.suruburi = rand() % 10 + 5;
            D. oreUmane = rand() % 4 + 1;
            swap(generatorMoto[xr],generatorMoto[nrDefectiuniMoto--]);
            break;
        default:
            xr = rand() % nrDefectiuniBicicleta + 1;
            r = generatorBicicleta[xr];
            D.piesaAfectata = listaDefectiuniPosibileBicicleta[r].second;
            D.tipDefectiune = listaDefectiuniPosibileBicicleta[r].first;
            if(D.tipDefectiune == "defectiune capitala")
            {
                break;
            }
            D.materialNecesar = MaterialeBicicleta[r].first;
            D.pret = preturi[MaterialeBicicleta[r].second];
            D.cantitate = rand() % cantitateMaxima[MaterialeBicicleta[r].second] + 1;
            D.pret *= D.cantitate;
            if(materialeDisponibile[MaterialeBicicleta[r].second] - D.cantitate < 0)
            {
                D.tipDefectiune = "lipsa materiale";
                break;
            }
            materialeDisponibile[MaterialeBicicleta[r].second] -= D.cantitate;
            D.suruburi = rand() % 10 + 5;
            D. oreUmane = rand() % 4 + 1;
            swap(generatorBicicleta[xr],generatorBicicleta[nrDefectiuniBicicleta--]);
            break;
    }
    return D;
}



istream& operator>>(istream &in, Defectiune &defectiune)
{
    cout<<"Introduceti piesa afectata";
    cout<<"\n";
    cin>>defectiune.piesaAfectata;
    cout<<"Introduceti tipul defectiunii";
    cout<<'\n';
    getline(cin >> ws, defectiune.tipDefectiune);
    cout<<"Introduceti cantitatea de afectare";
    cout<<'\n';
    cin>>defectiune.cantitate;
    return in;
}

ostream& operator<<(ostream &out, Defectiune &defectiune)
{
    cout << "Pretul repararii defectiunii " << defectiune.tipDefectiune << " la " << defectiune.piesaAfectata << " este " << defectiune.pret<<" lei."<<" A fost nevoie de "<<defectiune.materialNecesar<<".";
    return out;
}

#pragma endregion

/*class Materiale
{
private:
    Defectiune d;
    string tip;
    int cantitate, pret;
public:
    Materiale(Defectiune d);
    //~Materiale();
    void calculareMateriale();
};

Materiale :: Materiale(Defectiune d)
{
    cout<<
}*/


#pragma region Vehicul
class Vehicul
{
private:
    string denumire;
    int tipvehicul, nrDefectiuni, pret;
    Defectiune defectiuni[6];
public:

    void set_defectiuni(Defectiune defectiuni[]);
    void set_denumire(string denumire);
    void set_tipvehicul(int tipvehicul);
    void set_nrDefectiuni(int nrDefectiuni);
    void set_pret(int pret);

    Defectiune * get_defectiuni();
    string get_denumire();
    int get_tipvehicul();
    int get_nrDefectiuni();
    int get_pret();

    void printdefectiuni();
    Vehicul();
    //~Vehicul();*/
    friend ostream& operator<<(ostream &out, Vehicul &vehicul);
};

Vehicul :: Vehicul()
{
    nrDefectiuniAuto = nrDefectiuniAutoInit;
    nrDefectiuniMoto = nrDefectiuniMotoInit;
    nrDefectiuniBicicleta = nrDefectiuniBicicletaInit;
    srand(time(NULL));
    tipvehicul = rand() % 3 + 1;
    switch(tipvehicul)
    {
        case 1:
            denumire = "automobil";
            break;
        case 2:
            denumire = "motocicleta";
            break;
        default:
            denumire = "bicicleta";
            break;
    }
    nrDefectiuni = rand() % 5 + 1;
    this->pret = 0;
    for(int i = 1; i<= nrDefectiuni; i++)
    {
        defectiuni[i] = defectiuni[i].generareDefectiune(defectiuni[i], tipvehicul);
        string tip = defectiuni[i].get_tipDefectiune();
        if(tip == "defectiune capitala")
        {
            this ->pret = 0;
            defectiuni[0].set_tipVehicul(-1);
            break;
        }
        if(tip == "lipsa materiale")
        {
            this ->pret = 0;
            defectiuni[0].set_tipVehicul(-2);
            break;
        }
        this->pret += defectiuni[i].get_pret();
    }
}

void Vehicul :: set_pret(int pret)
{
    this->pret = pret;
}

int Vehicul :: get_pret()
{
    return pret;
}

void Vehicul :: printdefectiuni()
{
    if(defectiuni[0].get_tipVehicul() == -1)
    {
        cout << "Vehiculul nu a putut fi reparat, defectiunea este capitala\n";
        return;
    }
    if(defectiuni[0].get_tipVehicul() == -2)
    {
        cout << "Vehiculul nu a putut fi reparat, nu avem piesele pe stoc. Reveniti sau incercati la serviceul partener\n";
        return;
    }
    for(int i = 1; i<= nrDefectiuni; i++)
    {
        cout<< defectiuni[i]<<"\n";
    }
}

ostream& operator<<(ostream &out, Vehicul &vehicul)
{
    cout << "Vehiculul sosit este de tipul "<<vehicul.denumire<<".\n";
    cout << "S-au constatat si reparat, in cazul in care a fost posibil, urmatoarele defectiuni:\n";
    vehicul.printdefectiuni();
    return out;
}

#pragma endregion

void initializare()
{
    srand(time(NULL));
    int r, i;
    for(i = 1; i<= 14; i++)
    {
        r = rand() % 10 + 1;
        materialeDisponibile[i] += r;
    }
}

void diagnosticare(int &nrv, int &pret)
{
    Vehicul a;
    cout<<a;
    nrv++;
    pret += a.get_pret();
}

void aprovizionare()
{
    srand(time(NULL));
    int r, i;
    for(i = 1; i<= 14; i++)
    {
        r = rand() % 10 + 1;
        materialeDisponibile[i] += r;
    }
    cout<<"Aprovizionare realizata cu succes";
}

void afisaresesiune(int nrv, int pret)
{
    cout<<"In sesiunea curenta au fost testate "<<nrv<<" vehicule si a fost obtinut un profit total de "<<pret<<" lei.\n";
}

void meniu()
{
    initializare();
    int nrVehicule = 0, pretTotal = 0;
    while(true)
    {
        cout<<"\nBun venit in aplicatia seviceului auto. Introduceti o optiune:\n\n";
        cout<<"1) Diagnosticare si reparare vehicul\n";
        cout<<"2) Primire aprovizionare cu materiale\n";
        cout<<"3) Afisare numar de vehicule testate in sesiunea curenta si profit total\n";
        cout<<"0) Terminare sesiune\n";
        int opt;
        cin>>opt;
        switch(opt)
        {
            case 1:
                diagnosticare(nrVehicule, pretTotal);
                break;
            case 2:
                aprovizionare();
                break;
            case 3:
                afisaresesiune(nrVehicule,pretTotal);
                break;
            default:
                exit(0);

        }
    }
}

int main() {
    meniu();
    return 0;
}
