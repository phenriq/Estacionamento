#include <iostream>
#ifndef CARROMODEL_H
#define CARROMODEL_H

using namespace std;

class CarroModel
{
public:
    CarroModel();
    string placa;
    string cor;
    string marca;
    string modelo;
    string cidade;
    string uf;
    bool validarCarro(string placa,string cor,string marca,string modelo,string cidade,string uf);
    bool encontrarCarro(string placa);
    bool salvarEntrada(string placa);
    bool salvarSaida(string placa);
    bool salvarNovoCarro(CarroModel newCarro);
    bool salvarNewCor(string newCor);
    bool salvarNewModelo(string newModelo);
    bool salvarNewMarca(string newMarca);
    bool salvarNewCidade(string newCidade);
    bool salvarNewUf(string newUf);
};

#endif // CARROMODEL_H
