// This file is distributed under GNU GPLv3 license. For full license text, see <project-git-repository-root-folder>/LICENSE.md.

#include "saurus/gui/settings/settingsshortcuts.h"

#include "common/dynamic-shortcuts/dynamicshortcuts.h"
#include "saurus/miscellaneous/application.h"

SettingsShortcuts::SettingsShortcuts(Settings* settings, QWidget* parent)
  : SettingsPanel(settings, parent) {
  m_ui.setupUi(this);
  connect(m_ui.m_shortcuts, &DynamicShortcutsWidget::setupChanged, this, &SettingsShortcuts::dirtifySettings);
}

void SettingsShortcuts::loadSettings() {
  onBeginLoadSettings();
  m_ui.m_shortcuts->populate(qApp->userActions());
  onEndLoadSettings();
}

void SettingsShortcuts::saveSettings() {
  onBeginSaveSettings();
  m_ui.m_shortcuts->updateShortcuts();
  DynamicShortcuts::save(qApp->userActions(), qApp->settings());
  onEndSaveSettings();
}
