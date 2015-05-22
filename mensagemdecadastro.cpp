#include "mensagemdecadastro.h"
#include "ui_mensagemdecadastro.h"
#include "cadastrarcarro.h"

MensagemDeCadastro::MensagemDeCadastro(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MensagemDeCadastro)
{
    ui->setupUi(this);
}

MensagemDeCadastro::~MensagemDeCadastro()
{
    delete ui;
}

void MensagemDeCadastro::on_btnSim_clicked()
{
    CadastrarCarro objCadCarro;
    objCadCarro.setModal(true);
    objCadCarro.exec();

}
