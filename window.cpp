#include "window.h"
#include "ui_window.h"
#include "cadastrarcarro.h"
#include <QTime>
#include "Configs.h"
#include "controllerfile.h"
#include "pagamento.h"
#include <QMessageBox>
#include <iostream>
#include "mensagemdecadastro.h"

using namespace std;

Window::Window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Window)
{
    ui->setupUi(this);

    this->setWindowTitle(cliente);
    this->loadCarroNoPatio();

}

Window::~Window()
{
    delete ui;
}

void Window::on_btnCadastrar_clicked()
{
    CadastrarCarro objTelaCadastrarCarro;
    objTelaCadastrarCarro.setModal(true);
    objTelaCadastrarCarro.exec();
}

//5.0,"13-05-2015 19:00"
float Window::verificaValor(float precoHora, QString dateTime){

    float valor = 0.0;

    QStringList data = dateTime.split(" ");

    //Verificar se é o mesmo ano da retirada


    //pega a hora atual
    int horaRetirada = QTime::currentTime().hour();
    int minutoRetirada = QTime::currentTime().minute();



    //Pega a hora e minutos que foi estacionada
    QStringList tempo = data[1].split(":");
    int minutoEstacionado = tempo[1].toInt();
    int horaEstacionada = tempo[0].toInt();

    int qtHoras = horaRetirada - horaEstacionada;
    int qtMinutos = minutoRetirada - minutoEstacionado;

    if(qtHoras > 0){
        valor += qtHoras * precoHora;
    }
    if(qtMinutos > 0){
        valor += (precoHora/60) * qtMinutos;
    }

    return valor;

}

void Window::loadCarroNoPatio(){
    ControllerFile carro;
    QStringList carros = carro.getPatio();

    this->ui->lblTelaCarros->setText("Carros Estacionados: "+QString::number(carros.length()));

    foreach (QString itemCarro, carros) {
        QTreeWidgetItem *item = new QTreeWidgetItem(ui->twListaCarros);

        QStringList carroFatiado = itemCarro.split(",");

        item->setText(0,carroFatiado[0]);
        item->setText(1,carroFatiado[1]);
        item->setText(2,carroFatiado[2]);
        item->setText(3,carroFatiado[3]);
        item->setText(4,carroFatiado[4]);

        ui->twListaCarros->addTopLevelItem(item);
    }

}

void Window::on_btnSaida_clicked()
{
//    Pagamento telaPagamento;
//    telaPagamento.setModal(true);
//    telaPagamento.exec();

//    QTreeWidgetItem *item = ui->twListaCarros->currentItem();
//    if(this->pagamento(item)){
//        delete item;
//    }
}

bool Window::pagamento(QTreeWidgetItem item){
//    ControllerFile pagamento;
//    if(pagamento.update(pagamento.arfPatio,item[0],item))
//        return true;
//    return false;
}

void Window::setCarrosEstacionados(QString placa, QString estado, QString cidade, QString cor, QString marca, QString modelo){

    if(!placa.isNull() && !estado.isNull() && !cidade.isNull() && !cor.isNull() && !marca.isNull() && !modelo.isNull()){
        ControllerFile control;
        QString conteudo = placa.trimmed() + "," + modelo.trimmed() + "," + marca.trimmed() + "," + cor.trimmed() + "," + cidade.trimmed() + "," + estado.trimmed();
        control.gravaArquivo(control.arfCarros, conteudo);

        return;
    }
    QMessageBox::warning(NULL, "Error", "Erro ao tentar cadastrar carro \n Favor preencher todos os campos");
}

void Window::on_btnProcurar_clicked()
{
    if(this->ui->txtBuscaPlaca->text() != NULL){
        ControllerFile control;

        if(control.findPlacaPatio(control.arfPatio, this->ui->txtBuscaPlaca->text())){
            cout << "Insere o Horario de saida\nExibi tela pagamento com valor" << endl;
            return;
        }else if(control.findPlacaCarros(control.arfCarros, this->ui->txtBuscaPlaca->text())){
            ControllerFile control;
            control.gravaEntrada(this->ui->txtBuscaPlaca->text());

            return;
        }else{

            MensagemDeCadastro objMensagem;
            objMensagem.setModal(true);
            objMensagem.exec();

            return;
        }
        return;
    }
    QMessageBox::critical(NULL, "Error", "Operação Invalida\nVerifique os Campos");
}
