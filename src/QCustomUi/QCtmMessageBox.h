#pragma once

#include "qcustomui_global.h"
#include "QCtmDialog.h"

class QAbstractButton;

class QCUSTOMUI_EXPORT QCtmMessageBox : public QCtmDialog
{
    Q_OBJECT

public:
	enum ButtonRole {
		// keep this in sync with QDialogButtonBox::ButtonRole and QPlatformDialogHelper::ButtonRole
		InvalidRole = -1,
		AcceptRole,
		RejectRole,
		DestructiveRole,
		ActionRole,
		HelpRole,
		YesRole,
		NoRole,
		ResetRole,
		ApplyRole,

		NRoles
	};

    enum StandardButton {
        // keep this in sync with QMessageBox::StandardButton and QPlatformDialogHelper::StandardButton
        NoButton = 0x00000000,
        Ok = 0x00000400,
        Save = 0x00000800,
        SaveAll = 0x00001000,
        Open = 0x00002000,
        Yes = 0x00004000,
        YesToAll = 0x00008000,
        No = 0x00010000,
        NoToAll = 0x00020000,
        Abort = 0x00040000,
        Retry = 0x00080000,
        Ignore = 0x00100000,
        Close = 0x00200000,
        Cancel = 0x00400000,
        Discard = 0x00800000,
        Help = 0x01000000,
        Apply = 0x02000000,
        Reset = 0x04000000,
        RestoreDefaults = 0x08000000,

#ifndef Q_MOC_RUN
        FirstButton = Ok,
        LastButton = RestoreDefaults
#endif
    };

	Q_DECLARE_FLAGS(StandardButtons, StandardButton)

    Q_FLAG(StandardButtons)

    enum Icon {
        // keep this in sync with QMessageDialogOptions::Icon
        NoIcon = 0,
        Information = 1,
        Warning = 2,
        Critical = 3,
        Question = 4
    };
    Q_ENUM(Icon)

    QCtmMessageBox(QWidget *parent = Q_NULLPTR);
    QCtmMessageBox(Icon icon
        , const QString &title
        , const QString &text
        , StandardButtons buttons = NoButton
        , QWidget *parent = Q_NULLPTR
        , Qt::WindowFlags f = Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
    ~QCtmMessageBox();

    void setDefaultButton(StandardButton button);
    StandardButton defaultButton();
    QAbstractButton* clickedButton() const;
    StandardButton standardButton(QAbstractButton* button) const;
	void addButton(QAbstractButton* button, ButtonRole role);
	QPushButton* addButton(const QString& text, ButtonRole role);
	QPushButton* addButton(StandardButton button);

	void removeButton(QAbstractButton* button);

    static StandardButton critical(QWidget *parent
        , const QString &title
        , const QString &text
        , StandardButtons buttons = Ok
        , StandardButton defaultButton = NoButton);

    static StandardButton information(QWidget *parent
        , const QString &title
        , const QString &text
        , StandardButtons buttons = Ok
        , StandardButton defaultButton = NoButton);

    static StandardButton question(QWidget *parent
        , const QString &title
        , const QString &text
        , StandardButtons buttons = StandardButtons(Yes | No)
        , StandardButton defaultButton = NoButton);

    static StandardButton warning(QWidget *parent
        , const QString &title
        , const QString &text
        , StandardButtons buttons = Ok
        , StandardButton defaultButton = NoButton);

protected:
    void showEvent(QShowEvent *event) override;

private:
    void init();
    int layoutMinimumWidth();
    void updateSize();
    void detectEscapeButton() const;
private:
    struct Impl;
    std::unique_ptr<Impl> m_impl;
};

Q_DECLARE_OPERATORS_FOR_FLAGS(QCtmMessageBox::StandardButtons)