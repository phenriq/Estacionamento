#include "cadastrarnovouser.h"
#include "ui_cadastrarnovouser.h"
#include "controllerfile.h"
#include "dialog.h"

CadastrarNovoUser::CadastrarNovoUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CadastrarNovoUser)
{
    ui->setupUi(this);
}

CadastrarNovoUser::~CadastrarNovoUser()
{
    delete ui;
}

void CadastrarNovoUser::on_pushButton_clicked()
{
    QString conteudo = this->ui->txtNewUser->text() + "," + this->ui->txtNewPassword->text();

    ControllerFile gravaNewUser;
    gravaNewUser.gravaArquivo(gravaNewUser.arfUser, conteudo);

    Dialog telaLogin;
    telaLogin.setModal(true);
    telaLogin.exec();
}
