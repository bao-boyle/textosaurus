// This file is distributed under GNU GPLv3 license. For full license text, see <project-git-repository-root-folder>/LICENSE.md.

#ifndef MARKDOWNPLUGIN_H
#define MARKDOWNPLUGIN_H

#include <QObject>

#include "saurus/plugin-system/pluginbase.h"

class MarkdownSidebar;
class WebFactory;

class MarkdownPlugin : public QObject, public PluginBase {
  Q_OBJECT

  //Q_PLUGIN_METADATA(IID "io.github.martinrotter.textosaurus.markdownsimple")
  Q_INTERFACES(PluginBase)

  friend class MarkdownSidebar;

  public:
    explicit MarkdownPlugin(QObject* parent = nullptr);

    virtual QString name() const override;
    virtual QString id() const override;
    virtual QList<BaseSidebar*> sidebars() override;
    virtual QList<QAction*> userActions() override;
    virtual void start(QWidget* main_form_widget, TextApplication* text_app,
                       Settings* settings, IconFactory* icon_factory,
                       WebFactory* web_factory) override;
    virtual void stop() override;

  private:
    MarkdownSidebar* sidebar();

  private:
    TextApplication* m_textApp;
    MarkdownSidebar* m_sidebar;
    IconFactory* m_iconFactory;
    WebFactory* m_webFactory;
};

#endif // MARKDOWNPLUGIN_H
