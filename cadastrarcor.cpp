#include "cadastrarcor.h"
#include "ui_cadastrarcor.h"
#include "Configs.h"
#include "cadastrarcarro.h"

CadastrarCor::CadastrarCor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CadastrarCor)
{
    ui->setupUi(this);
    this->setWindowTitle((QString)cliente + " - Adicionar Nova Cor");
}

CadastrarCor::~CadastrarCor()
{
    delete ui;
}

void CadastrarCor::on_btnNovaCor_clicked()
{
    CadastrarCarro cadCor;
    cadCor.setNewCor(this->ui->txtNovaCor->text());
}
