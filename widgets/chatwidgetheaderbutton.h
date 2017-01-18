#ifndef CHATWIDGETHEADERBUTTON_H
#define CHATWIDGETHEADERBUTTON_H

#include "widgets/chatwidgetheaderbuttonlabel.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QPaintEvent>
#include <QWidget>

namespace chatterino {
namespace widgets {

class ChatWidgetHeaderButton : public QWidget
{
    Q_OBJECT

public:
    ChatWidgetHeaderButton();

    ChatWidgetHeaderButtonLabel &
    getLabel()
    {
        return label;
    }

signals:
    void clicked();

protected:
    void paintEvent(QPaintEvent *) Q_DECL_OVERRIDE;

    void enterEvent(QEvent *) Q_DECL_OVERRIDE;
    void leaveEvent(QEvent *) Q_DECL_OVERRIDE;

    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;

private:
    QHBoxLayout hbox;
    ChatWidgetHeaderButtonLabel label;

    bool mouseOver;
    bool mouseDown;

    void labelMouseUp();
    void labelMouseDown();
};
}
}

#endif  // CHATWIDGETHEADERBUTTON_H