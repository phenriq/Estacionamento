#include "dialog.h"
#include "ui_dialog.h"
#include <QMessageBox>
#include "window.h"
#include "controllerfile.h"
#include "Configs.h"
#include "cadastrarnovouser.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->setWindowTitle((QString)cliente + " - Login");
}

Dialog::~Dialog()
{
    delete ui;
}
/*Verifica Login e senha*/
void Dialog::on_btnLogin_clicked()
{
    ControllerFile controller;
    QStringList usuarios = controller.getLogins();

    foreach (QString usuario, usuarios) {

        QStringList user = usuario.split(",");

        if(ui->txtLogin->text().toStdString() == "admin" && ui->txtSenha->text().toStdString() == "admin"){
            this->close();
            CadastrarNovoUser objNewUser;
            objNewUser.setModal(true);
            objNewUser.exec();
            return ;

        }else if(ui->txtLogin->text().toStdString() == user[0].toStdString() && user[1].compare(ui->txtSenha->text()) == 1){
            this->close();
            Window objJanelaPrincipal;
            objJanelaPrincipal.setModal(true);
            objJanelaPrincipal.exec();
            return ;
        }
    }

    QMessageBox::critical(NULL,"ERROR","Login ou senha inválido");
    ui->txtLogin->setText("");
    ui->txtSenha->setText("");

}
