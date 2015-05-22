#ifndef PAGAMENTO_H
#define PAGAMENTO_H

#include <QDialog>

namespace Ui {
class Pagamento;
}

class Pagamento : public QDialog
{
    Q_OBJECT

public:
    explicit Pagamento(QWidget *parent = 0);
    ~Pagamento();

private:
    Ui::Pagamento *ui;
};

#endif // PAGAMENTO_H
