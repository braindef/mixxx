#ifndef SKINLOADER_H
#define SKINLOADER_H

#include <QWidget>

#include "configobject.h"

class MixxxKeyboard;
class PlayerManager;
class Library;
class MixxxView;

class SkinLoader {
  public:
    SkinLoader(ConfigObject<ConfigValue>* pConfig);
    QWidget* loadDefaultSkin(QWidget* pParent,
                               MixxxKeyboard* pKeyboard,
                               PlayerManager* pPlayerManager,
                               Library* pLibrary);
                               
	QWidget* loadCustomSkin(QString custom_skinpath, 
							   QWidget* pParent,
                               MixxxKeyboard* pKeyboard,
                               PlayerManager* pPlayerManager,
                               Library* pLibrary);                               	

    QString getConfiguredSkinPath();

  private:
    ConfigObject<ConfigValue>* m_pConfig;
};


#endif /* SKINLOADER_H */

