#include "user_profile.h"
#include "ui_user_profile.h"


UserProfile::UserProfile(QWidget *parent) : QWidget(parent), ui(new Ui::UserProfile) {
    ui->setupUi(this);

    /* fixme: no check if parent is NULL */
    this->DropdownMenu = new UserDropdown(parent->parentWidget(), ui->dropdownButton, this);
    DropdownMenu->hide();

    connect(ui->dropdownButton, &QPushButton::clicked, DropdownMenu, &UserDropdown::onDropdownButtonClicked);

    connect(ui->switchButton, &QPushButton::clicked, DropdownMenu, [=]() {
        if (ui->userStatus->isVisible()) {
            ui->userStatus->hide();
            ui->userName->setText("Brandon User");
        } else {
            ui->userStatus->show();
            ui->userName->setText("Brandon Miles");
        }
    });

}

UserProfile::~UserProfile() {
    delete ui;
}
