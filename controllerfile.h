#ifndef CONTROLLERFILE_H
#define CONTROLLERFILE_H
#include <QtCore>

class ControllerFile
{
public:
    ControllerFile();

    QString arfCidade = "../SansCar/sourse/data/cidades.csv";
//    QString arfEstado = "../SansCar/sourse/data/estados.csv";
    QString arfCor = "../SansCar/sourse/data/cores.csv";
    QString arfUser = "../SansCar/sourse/data/user.csv";
    QString arfMarca = "../SansCar/sourse/data/marcas.csv";
//    QString arfModelo = "../SansCar/sourse/data/modelos.csv";
    QString arfCarros = "../SansCar/sourse/data/carros.csv";
    QString arfPatio = "../SansCar/sourse/data/patio.csv";

    QStringList leArquivo(QString nomeArquivo);
    bool gravaArquivo(QString nomeArquivo, QString conteudo);
    bool update(QString arfUp, QString pk, QString item);


    //retorna lista de estados
    QStringList getEstado();
    //grava o novo estado
    bool setEstado(QString estado);
    //retorna lista de cidades
    QStringList getCidade();
    //grava a nova cidade
    bool setCidade(QString cidade);
    //retorna lista de cor
    QStringList getCor();
    //grava a nova cor
    bool setCor(QString cor);
    //retorna lista de marca
    QStringList getMarca();
    //grava a nova marca
    bool setMarca(QString marca);
    //retorna lista de modelo
    QStringList getModelo();
    //grava o novo modelo
    bool setModelo(QString modelo);
    //Busca logins e senhas
    QStringList getLogins();

    QStringList getPatio();

    bool findPlacaPatio(QString arfPatio, QString placa);
    bool findPlacaCarros(QString arfCarros, QString placa);
    void gravaEntrada(QString placa);
    QStringList findCarro(QString placa);

};

#endif // CONTROLLERFILE_H
