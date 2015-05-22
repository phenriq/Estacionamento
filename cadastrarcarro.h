#ifndef CADASTRARCARRO_H
#define CADASTRARCARRO_H

#include <QDialog>

namespace Ui {
class CadastrarCarro;
}

class CadastrarCarro : public QDialog
{
    Q_OBJECT

public:
    explicit CadastrarCarro(QWidget *parent = 0);
    ~CadastrarCarro();

    bool setNewCidade(QString cidade, QString uf);
    bool setNewModelo(QString modelo, QString marca);
    bool setNewCor(QString cor);

private slots:

    void on_btnAddCor_clicked();

    void on_btnAddModelo_clicked();

    void on_btnAddCidade_clicked();

    void on_btnCadastrar_clicked();

private:
    Ui::CadastrarCarro *ui;

    bool preencheTelaUf();
    bool preencheTelaCidade();
    bool preencheTelaCor();
    bool preencheTelaMarca();
    bool preencheTelaModelo();

};

#endif // CADASTRARCARRO_H
