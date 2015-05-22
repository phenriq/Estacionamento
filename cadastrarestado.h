#ifndef CADASTRARESTADO_H
#define CADASTRARESTADO_H

#include <QDialog>

namespace Ui {
class CadastrarEstado;
}

class CadastrarEstado : public QDialog
{
    Q_OBJECT

public:
    explicit CadastrarEstado(QWidget *parent = 0);
    ~CadastrarEstado();

private slots:
    void on_btnAddNovaUf_clicked();

private:
    Ui::CadastrarEstado *ui;
};

#endif // CADASTRARESTADO_H
