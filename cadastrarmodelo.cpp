#include "cadastrarmodelo.h"
#include "ui_cadastrarmodelo.h"
#include "cadastrarmarca.h"
#include "controllerfile.h"
#include "Configs.h"
#include "cadastrarcarro.h"

cadastrarModelo::cadastrarModelo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cadastrarModelo)
{
    ui->setupUi(this);
    this->preencheTelaMarca();
    this->setWindowTitle((QString)cliente + " - Adicionar Novo Modelo");
}

cadastrarModelo::~cadastrarModelo()
{
    delete ui;
}

void cadastrarModelo::on_commandLinkButton_clicked()
{
    cadastrarMarca addMarca;
    addMarca.setModal(true);
    addMarca.exec();
}

bool cadastrarModelo::preencheTelaMarca(){

    ControllerFile objMarcas;
    QStringList marcas = objMarcas.getMarca();
    foreach (QString marca, marcas) {
        this->ui->cbMarca->addItem(marca);
    }
}

bool cadastrarModelo::setNewMarca(QString NewMarca){

    this->ui->cbMarca->addItem(NewMarca);
    this->close();
    this->exec();

}

void cadastrarModelo::on_pushButton_clicked()
{
    CadastrarCarro cadModelo;
    cadModelo.setNewModelo(this->ui->txtModelo->text(), this->ui->cbMarca->currentText());

}
