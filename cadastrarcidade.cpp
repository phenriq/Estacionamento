#include "cadastrarcidade.h"
#include "ui_cadastrarcidade.h"
#include "cadastrarestado.h"
#include "controllerfile.h"
#include "Configs.h"
#include "cadastrarcarro.h"

CadastrarCidade::CadastrarCidade(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CadastrarCidade)
{
    ui->setupUi(this);
    this->preencheTelaUf();
    this->setWindowTitle((QString)cliente + " - Adicionar Nova Cidade");
}

CadastrarCidade::~CadastrarCidade()
{
    delete ui;
}

void CadastrarCidade::on_commandLinkButton_clicked()
{
    CadastrarEstado addUf;
    addUf.setModal(true);
    addUf.exec();
}

bool CadastrarCidade::preencheTelaUf(){

    ControllerFile objEstados;
    QStringList ufs = objEstados.getEstado();
    foreach (QString estado, ufs) {
        this->ui->cbEstado->addItem(estado);
    }

}

bool CadastrarCidade::setNewEstado(QString newEstado){

    this->ui->cbEstado->addItem(newEstado);
    this->close();
    this->exec();

}

void CadastrarCidade::on_pushButton_clicked()
{
    CadastrarCarro cadCidade;
    cadCidade.setNewCidade(this->ui->lineEdit->text(), this->ui->cbEstado->currentText());
}
