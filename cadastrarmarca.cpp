#include "cadastrarmarca.h"
#include "ui_cadastrarmarca.h"
#include "Configs.h"
#include "cadastrarmodelo.h"

cadastrarMarca::cadastrarMarca(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cadastrarMarca)
{
    ui->setupUi(this);
    this->setWindowTitle((QString)cliente + " - Adicionar Nova Marca");
}

cadastrarMarca::~cadastrarMarca()
{
    delete ui;
}

void cadastrarMarca::on_pushButton_clicked()
{
    cadastrarModelo novaMarca;
    novaMarca.setNewMarca(this->ui->txtNovaMarca->text());

}
