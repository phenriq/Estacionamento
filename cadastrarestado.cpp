#include "cadastrarestado.h"
#include "ui_cadastrarestado.h"
#include "Configs.h"
#include "controllerfile.h"
#include "cadastrarcidade.h"

CadastrarEstado::CadastrarEstado(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CadastrarEstado)
{
    ui->setupUi(this);
    this->setWindowTitle((QString)cliente + " - Adicionar Novo Estado");
}

CadastrarEstado::~CadastrarEstado()
{
    delete ui;
}

void CadastrarEstado::on_btnAddNovaUf_clicked()
{
    CadastrarCidade novoEstado;
    novoEstado.setNewEstado(this->ui->txtNovaUf->text());

}
