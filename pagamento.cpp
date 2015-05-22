#include "pagamento.h"
#include "ui_pagamento.h"

Pagamento::Pagamento(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Pagamento)
{
    ui->setupUi(this);
}

Pagamento::~Pagamento()
{
    delete ui;
}
