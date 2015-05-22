#ifndef MENSAGEMDECADASTRO_H
#define MENSAGEMDECADASTRO_H

#include <QDialog>

namespace Ui {
class MensagemDeCadastro;
}

class MensagemDeCadastro : public QDialog
{
    Q_OBJECT

public:
    explicit MensagemDeCadastro(QWidget *parent = 0);
    ~MensagemDeCadastro();

private slots:
    void on_btnSim_clicked();

private:
    Ui::MensagemDeCadastro *ui;
};

#endif // MENSAGEMDECADASTRO_H
