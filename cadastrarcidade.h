#ifndef CADASTRARCIDADE_H
#define CADASTRARCIDADE_H

#include <QDialog>

namespace Ui {
class CadastrarCidade;
}

class CadastrarCidade : public QDialog
{
    Q_OBJECT

public:
    explicit CadastrarCidade(QWidget *parent = 0);
    ~CadastrarCidade();
    bool setNewEstado(QString newEstado);

private slots:
    void on_commandLinkButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::CadastrarCidade *ui;

    bool preencheTelaUf();

};

#endif // CADASTRARCIDADE_H
