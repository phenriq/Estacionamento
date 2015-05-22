#include "cadastrarcarro.h"
#include "ui_cadastrarcarro.h"
#include "cadastrarcor.h"
#include "cadastrarmarca.h"
#include "cadastrarmodelo.h"
#include "cadastrarcidade.h"
#include "cadastrarestado.h"
#include "carromodel.h"
#include "controllerfile.h"
#include "Configs.h"
#include "window.h"
#include <QMessageBox>

CadastrarCarro::CadastrarCarro(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CadastrarCarro)
{
    ui->setupUi(this);
    ui->txtPlaca->setMaxLength(8);
    this->preencheTelaUf();
    this->preencheTelaCidade();
    this->preencheTelaCor();
    this->preencheTelaMarca();
    this->preencheTelaModelo();
    this->setWindowTitle((QString)cliente + " - Cadastro de Carros");

}

CadastrarCarro::~CadastrarCarro()
{
    delete ui;
}

void CadastrarCarro::on_btnAddCor_clicked()
{
    CadastrarCor addCor;
    addCor.setModal(true);
    addCor.exec();
}

void CadastrarCarro::on_btnAddModelo_clicked()
{
    cadastrarModelo addModelo;
    addModelo.setModal(true);
    addModelo.exec();
}

void CadastrarCarro::on_btnAddCidade_clicked()
{
    CadastrarCidade addCidade;
    addCidade.setModal(true);
    addCidade.exec();
}

bool CadastrarCarro::preencheTelaUf(){

    ControllerFile objEstados;
    QStringList ufs = objEstados.getEstado();
    foreach (QString estado, ufs) {
        this->ui->cbEstado->addItem(estado);
    }
}
bool CadastrarCarro::preencheTelaCidade(){

    ControllerFile objCidades;
    QStringList cidades = objCidades.getCidade();
    foreach (QString cidade, cidades) {
        this->ui->cbCidade->addItem(cidade);
    }
}
bool CadastrarCarro::preencheTelaCor(){

    ControllerFile objCores;
    QStringList cores = objCores.getCor();
    foreach (QString cor, cores) {
        this->ui->cbCor->addItem(cor);
    }
}
bool CadastrarCarro::preencheTelaMarca(){

    ControllerFile objMarcas;
    QStringList marcas = objMarcas.getMarca();
    foreach (QString marca, marcas) {
        this->ui->cbMarca->addItem(marca);
    }
}
bool CadastrarCarro::preencheTelaModelo(){

    ControllerFile objModelos;
    QStringList modelos = objModelos.getModelo();
    foreach (QString modelo, modelos) {
        this->ui->cbModelo->addItem(modelo);
    }
}

bool CadastrarCarro::setNewCidade(QString cidade, QString uf){

    if(!cidade.isEmpty()){
        this->ui->cbCidade->addItem(cidade);
    }if(!uf.isEmpty()){
        this->ui->cbEstado->addItem(uf);
    }

    this->close();

    if(!cidade.isEmpty() && !uf.isEmpty()){

        QString conteudo = cidade + "," + uf;

        ControllerFile gravaCidade;
        gravaCidade.gravaArquivo(gravaCidade.arfCidade, conteudo);

    }
    this->exec();
}

bool CadastrarCarro::setNewModelo(QString modelo, QString marca){

    if(!modelo.isEmpty())
        this->ui->cbModelo->addItem(modelo);
    if(!marca.isEmpty())
        this->ui->cbMarca->addItem(marca);

    this->close();

    if(!modelo.isEmpty() && !marca.isEmpty()){

        QString conteudo = modelo + "," + marca;

        ControllerFile gravaModelo;

        gravaModelo.gravaArquivo(gravaModelo.arfMarca, conteudo);

    }
    this->exec();
}

bool CadastrarCarro::setNewCor(QString cor){

    if(!cor.isEmpty())
        this->ui->cbCor->addItem(cor);

    this->close();

    if(!cor.isEmpty()){

        QString conteudo = cor;

        ControllerFile gravaCor;

        gravaCor.gravaArquivo(gravaCor.arfCor, conteudo);
    }
    this->exec();
}

void CadastrarCarro::on_btnCadastrar_clicked()
{
    QString placa = this->ui->txtPlaca->text();
    QString estado = this->ui->cbEstado->currentText();
    QString cidade = this->ui->cbCidade->currentText();
    QString cor = this->ui->cbCor->currentText();
    QString modelo = this->ui->cbModelo->currentText();
    QString marca = this->ui->cbMarca->currentText();


    if(placa != NULL || !placa.isEmpty()){
        Window cadCarros;
        cadCarros.setCarrosEstacionados(placa,estado,cidade,cor,marca,modelo);
        return;
    }

    QMessageBox::warning(NULL, "Error", "Erro ao tentar cadastrar carro \nFavor preencher todos os campos");
}
