#include "carromodel.h"
#include <QMessageBox>


CarroModel::CarroModel()
{
}
bool CarroModel::validarCarro(string placa,string cor,string marca,string modelo,string cidade,string uf){

    QStringList erros;

    if(placa.empty() || placa.length() < 8){
        erros.append("Placa");
    }
    if(cor.empty() || cor.length() < 4){
        erros.append("Cor");
    }
    if(marca.empty() || marca.length() < 4){
        erros.append("Marca");
    }
    if(modelo.empty() || modelo.length() < 2){
        erros.append("Modelo");
    }
    if(cidade.empty() || cidade.length() < 3){
        erros.append("Cidade");
    }
    if(uf.empty() || uf.length() != 2){
        erros.append("UF/Estado");
    }
    if(!erros.isEmpty()){
        QString erro = "Campos inválidos:\n", er;
        foreach (er, erros){
            erro = erro+"\n"+er;
        }
        QMessageBox::critical(NULL,"ERROR",erro);
    }
}
