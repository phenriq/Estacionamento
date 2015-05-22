#ifndef CADASTRARMODELO_H
#define CADASTRARMODELO_H

#include <QDialog>

namespace Ui {
class cadastrarModelo;
}

class cadastrarModelo : public QDialog
{
    Q_OBJECT

public:
    explicit cadastrarModelo(QWidget *parent = 0);
    ~cadastrarModelo();

    bool setNewMarca(QString NewMarca);

private slots:
    void on_commandLinkButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::cadastrarModelo *ui;

    bool preencheTelaMarca();
};

#endif // CADASTRARMODELO_H
