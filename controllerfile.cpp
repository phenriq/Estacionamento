#include "controllerfile.h"
#include <iostream>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QDate>
#include <QTime>

using namespace std;

ControllerFile::ControllerFile()
{
}

QStringList ControllerFile::leArquivo(QString nomeArquivo){
    QFile meuArquivo(nomeArquivo);

    if(!meuArquivo.exists()){
        QMessageBox::critical(NULL, "Erro Critico", "arquivo "+nomeArquivo+ " não encontrado");
    }
    if(!meuArquivo.open(QFile::ReadOnly|QFile::Text)){
        QMessageBox::critical(NULL,"Erro Critico","Erro na tentativa de abrir o arquivo " +nomeArquivo);
    }
    QStringList listaDoConteudoDoArquivo;
    while(!meuArquivo.atEnd()){
        QString linha = meuArquivo.readLine();
        listaDoConteudoDoArquivo.append(linha);
    }
    return listaDoConteudoDoArquivo;
}
bool ControllerFile::gravaArquivo(QString nomeArquivo, QString conteudo){

    QFile meuArquivo(nomeArquivo);

    if(!meuArquivo.open(QFile::Append|QFile::Text)){
        QMessageBox::critical(NULL,"Error", "Ocorreu um erro na tentativa de gravar o arquivo"+nomeArquivo);
        return 0;
    }else if(!meuArquivo.isOpen()){
        QMessageBox::critical(NULL,"Error", "Ocorreu um erro na tentativa de abrir o arquivo"+nomeArquivo);
        return 0;
    }else{
        QTextStream stream(&meuArquivo);
        stream << conteudo << endl;

        meuArquivo.flush();
        meuArquivo.close();
    }
    return 1;
}

bool ControllerFile::update(QString arfUp, QString pk, QString item){

    QStringList contem = this->leArquivo(arfUp);
    QString novoConteudo;

    foreach (QString conteudo, contem) {
        QStringList fatiaConteudo = conteudo.split(",");
        int qtConteudoNaLinha = fatiaConteudo.length();
        for(int i = 0; i<= qtConteudoNaLinha; i++){
            if(pk == fatiaConteudo[i]){
                novoConteudo += "," + item;
            }else{
                novoConteudo += "," + conteudo;
            }
        }
    }
    this->gravaArquivo(arfUp, novoConteudo);
}

QStringList ControllerFile::getEstado(){
    QStringList estados = this->leArquivo(this->arfCidade);
    QStringList uf;
    foreach (QString var, estados) {
        QStringList listaUfLinha = var.split(",");
        uf.append(listaUfLinha[1]);
    }
    uf.removeDuplicates();
    return uf;
}

QStringList ControllerFile::getCidade(){

    QStringList city = this->leArquivo(this->arfCidade);
    QStringList cidades;

    foreach (QString var, city) {
        QStringList listaCidadeLinha = var.split(",");
        cidades.append(listaCidadeLinha[0]);
    }
    cidades.removeDuplicates();
    return cidades;
}

QStringList ControllerFile::getCor(){
    QStringList colors = this->leArquivo(this->arfCor);
    QStringList cores;

    foreach (QString var, colors) {
        cores.append(var);
    }
    cores.removeDuplicates();
    return cores;
}

QStringList ControllerFile::getMarca(){
    QStringList marc = this->leArquivo(this->arfMarca);
    QStringList marcas;

    foreach (QString var, marc) {
        QStringList listaMarcasLinha = var.split(",");
        marcas.append(listaMarcasLinha[1]);
    }
    marcas.removeDuplicates();
    return marcas;
}


QStringList ControllerFile::getModelo(){
    QStringList model = this->leArquivo(this->arfMarca);
    QStringList modelos;

    foreach (QString var, model) {
        QStringList listaModeloLinha = var.split(",");
        modelos.append(listaModeloLinha[0]);
    }
    modelos.removeDuplicates();
    return modelos;
}

QStringList ControllerFile::getLogins(){
    QStringList usuarios = this->leArquivo(this->arfUser);

    return usuarios;
}

QStringList ControllerFile::getPatio(){
    QStringList patioCarros = this->leArquivo(this->arfPatio);
    QStringList soOsEmAberto;

    foreach (QString carro, patioCarros) {
        QStringList resultadoDaCarros = carro.split(",");
        if(resultadoDaCarros[7].isEmpty()){
            soOsEmAberto.append(resultadoDaCarros[0] + "," + resultadoDaCarros[2] + "," + resultadoDaCarros[1] + "," + resultadoDaCarros[3] + "," + resultadoDaCarros[6]);
        }
    }
    soOsEmAberto.removeDuplicates();
    return soOsEmAberto;
}

bool ControllerFile::findPlacaPatio(QString arfPatio, QString placa){

    QStringList carrosNoPatio = this->leArquivo(arfPatio);
    foreach (QString var, carrosNoPatio) {
        QStringList linha = var.split(",");
        if(linha[0] == placa && linha[7].isEmpty()){
            return 1;
        }
    }
    return 0;
}

bool ControllerFile::findPlacaCarros(QString arfCarros, QString placa){

    QStringList carrosNoArquivo = this->leArquivo(arfCarros);
    foreach (QString var, carrosNoArquivo) {
        QStringList linha = var.split(",");
        if(linha[0] == placa){
            return 1;
        }
    }
    return 0;
}
void ControllerFile::gravaEntrada(QString placa){

    QStringList carro = this->findCarro(placa);
    QString conteudo;

    foreach (QString var, carro) {
        conteudo += var.trimmed() + ",";
    }
    //insere a data
    QString dateTime = QString::number(QDate::currentDate().day()) + "-" + QString::number(QDate::currentDate().month()) + "-" + QString::number(QDate::currentDate().year()) + " " + QString::number(QTime::currentTime().hour()) + ":" + QString::number(QTime::currentTime().minute());
    conteudo += dateTime;

    cout << conteudo.toStdString() << endl;

//    this->gravaArquivo(this->arfPatio, conteudo);

}
QStringList ControllerFile::findCarro(QString placa){

    QStringList carrosNoArquivo = this->leArquivo(arfCarros);
    foreach (QString var, carrosNoArquivo) {
        QStringList linha = var.split(",");
        if(linha[0] == placa){
            return linha;
        }
    }
    return carrosNoArquivo;

}
