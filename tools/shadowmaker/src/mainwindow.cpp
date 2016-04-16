// generated by Fast Light User Interface Designer (fluid) version 1.0303

#include "mainwindow.hpp"
#include <ctime>
#include <string>
#include "misc.hpp"
#include <algorithm>
#include <FL/fl_ask.H>

void MainWindow::cb_m_Window_i(Fl_Double_Window*, void*) {
  {
	exit(0);
};
}
void MainWindow::cb_m_Window(Fl_Double_Window* o, void* v) {
  ((MainWindow*)(o->user_data()))->cb_m_Window_i(o,v);
}

void MainWindow::cb_Load_i(Fl_Menu_*, void*) {
  {
    Fl_Native_File_Chooser cFileChooser;
    cFileChooser.title("Load .WIL File");
    cFileChooser.options(Fl_Native_File_Chooser::NO_OPTIONS);
    cFileChooser.type(Fl_Native_File_Chooser::BROWSE_DIRECTORY);
    cFileChooser.directory(".");
    switch(cFileChooser.show()){
        case -1:
            fl_alert(cFileChooser.errmsg());
            break;
        case  1:
            break;
        default:
            {
                std::string szFolderName = cFileChooser.filename();
                std::replace(szFolderName.begin(), szFolderName.end(), '\\', '/');
                extern ValidWilFileWindow *g_ValidWilFileWindow;
                g_ValidWilFileWindow->CheckValidWilFile(szFolderName.c_str());
                g_ValidWilFileWindow->ShowAll();
            }
            m_Window->redraw();
            break;
    };
};
}
void MainWindow::cb_Load(Fl_Menu_* o, void* v) {
  ((MainWindow*)(o->parent()->user_data()))->cb_Load_i(o,v);
}

void MainWindow::cb_Export_i(Fl_Menu_*, void*) {
  {
    // MakeWorkingFolder();
    extern AnimationSet g_AnimationSet;
    if(!g_AnimationSet.Export()){
        fl_alert("Export animation failed!");
    }
};
}
void MainWindow::cb_Export(Fl_Menu_* o, void* v) {
  ((MainWindow*)(o->parent()->user_data()))->cb_Export_i(o,v);
}

void MainWindow::cb_Quit_i(Fl_Menu_*, void*) {
  exit(0);
}
void MainWindow::cb_Quit(Fl_Menu_* o, void* v) {
  ((MainWindow*)(o->parent()->user_data()))->cb_Quit_i(o,v);
}

void MainWindow::cb_m_MenuItemEnableEdit_i(Fl_Menu_*, void*) {
  m_MenuItemEnableAnimation->clear();
}
void MainWindow::cb_m_MenuItemEnableEdit(Fl_Menu_* o, void* v) {
  ((MainWindow*)(o->parent()->user_data()))->cb_m_MenuItemEnableEdit_i(o,v);
}

void MainWindow::cb_m_MenuItemEditCover_i(Fl_Menu_*, void*) {
  m_MenuItemEnableEdit->clear();
m_MenuItemEnableAnimation->clear();
m_TestGroup->StopTest();

RedrawAll();
}
void MainWindow::cb_m_MenuItemEditCover(Fl_Menu_* o, void* v) {
  ((MainWindow*)(o->parent()->user_data()))->cb_m_MenuItemEditCover_i(o,v);
}

void MainWindow::cb_m_MenuItemEditShadow_i(Fl_Menu_*, void*) {
  m_MenuItemEnableEdit->clear();
m_MenuItemEnableAnimation->clear();
m_TestGroup->StopTest();

RedrawAll();
}
void MainWindow::cb_m_MenuItemEditShadow(Fl_Menu_* o, void* v) {
  ((MainWindow*)(o->parent()->user_data()))->cb_m_MenuItemEditShadow_i(o,v);
}

void MainWindow::cb_m_MenuItemEditFrameAlign_i(Fl_Menu_*, void*) {
  m_MenuItemEnableEdit->clear();
m_MenuItemEnableAnimation->clear();
m_TestGroup->StopTest();

RedrawAll();
}
void MainWindow::cb_m_MenuItemEditFrameAlign(Fl_Menu_* o, void* v) {
  ((MainWindow*)(o->parent()->user_data()))->cb_m_MenuItemEditFrameAlign_i(o,v);
}

void MainWindow::cb_m_MenuItemEditActionSetAlign_i(Fl_Menu_*, void*) {
  m_MenuItemEnableEdit->clear();
m_MenuItemEnableAnimation->clear();
m_TestGroup->StopTest();

RedrawAll();
}
void MainWindow::cb_m_MenuItemEditActionSetAlign(Fl_Menu_* o, void* v) {
  ((MainWindow*)(o->parent()->user_data()))->cb_m_MenuItemEditActionSetAlign_i(o,v);
}

void MainWindow::cb_m_MenuItemDynamicShadow_i(Fl_Menu_*, void*) {
  m_MenuItemEnableEdit->clear();
m_MenuItemEnableAnimation->clear();
m_TestGroup->StopTest();

RedrawAll();
}
void MainWindow::cb_m_MenuItemDynamicShadow(Fl_Menu_* o, void* v) {
  ((MainWindow*)(o->parent()->user_data()))->cb_m_MenuItemDynamicShadow_i(o,v);
}

void MainWindow::cb_m_MenuItemTest_i(Fl_Menu_*, void*) {
  m_MenuItemEnableEdit->clear();
m_MenuItemEnableAnimation->clear();
m_TestGroup->StopTest();

RedrawAll();
}
void MainWindow::cb_m_MenuItemTest(Fl_Menu_* o, void* v) {
  ((MainWindow*)(o->parent()->user_data()))->cb_m_MenuItemTest_i(o,v);
}

void MainWindow::cb_About_i(Fl_Menu_*, void*) {
  extern AboutWindow *g_AboutWindow;
g_AboutWindow->ShowAll();
}
void MainWindow::cb_About(Fl_Menu_* o, void* v) {
  ((MainWindow*)(o->parent()->user_data()))->cb_About_i(o,v);
}

Fl_Menu_Item MainWindow::menu_m_MenuBar[] = {
 {"File", 0,  0, 0, 64, FL_NORMAL_LABEL, 4, 14, 0},
 {"Load Database        ", 0,  (Fl_Callback*)MainWindow::cb_Load, 0, 128, FL_NORMAL_LABEL, 4, 14, 0},
 {"Export        ", 0,  (Fl_Callback*)MainWindow::cb_Export, 0, 128, FL_NORMAL_LABEL, 4, 14, 0},
 {"Quit", 0,  (Fl_Callback*)MainWindow::cb_Quit, 0, 0, FL_NORMAL_LABEL, 4, 14, 0},
 {0,0,0,0,0,0,0,0,0},
 {"Layer", 0,  0, 0, 64, FL_NORMAL_LABEL, 4, 14, 0},
 {"Show Body        ", 0,  0, 0, 6, FL_NORMAL_LABEL, 4, 14, 0},
 {"Show Shadow", 0,  0, 0, 2, FL_NORMAL_LABEL, 4, 14, 0},
 {0,0,0,0,0,0,0,0,0},
 {"Line", 0,  0, 0, 64, FL_NORMAL_LABEL, 4, 14, 0},
 {"Rectangle Cover              ", 0,  0, 0, 2, FL_NORMAL_LABEL, 4, 14, 0},
 {"Body Frame", 0,  0, 0, 2, FL_NORMAL_LABEL, 4, 14, 0},
 {"Shadow Frame", 0,  0, 0, 2, FL_NORMAL_LABEL, 4, 14, 0},
 {0,0,0,0,0,0,0,0,0},
 {"Edit", 0,  0, 0, 64, FL_NORMAL_LABEL, 4, 14, 0},
 {"Enable Edit     ", 0,  (Fl_Callback*)MainWindow::cb_m_MenuItemEnableEdit, 0, 130, FL_NORMAL_LABEL, 4, 14, 0},
 {"Enable Animation", 0,  0, 0, 134, FL_NORMAL_LABEL, 4, 14, 0},
 {"Align Cover", 0,  (Fl_Callback*)MainWindow::cb_m_MenuItemEditCover, 0, 12, FL_NORMAL_LABEL, 4, 14, 0},
 {"Align Shadow      ", 0,  (Fl_Callback*)MainWindow::cb_m_MenuItemEditShadow, 0, 8, FL_NORMAL_LABEL, 4, 14, 0},
 {"Align Frame", 0,  (Fl_Callback*)MainWindow::cb_m_MenuItemEditFrameAlign, 0, 8, FL_NORMAL_LABEL, 4, 14, 0},
 {"Align Action Set        ", 0,  (Fl_Callback*)MainWindow::cb_m_MenuItemEditActionSetAlign, 0, 8, FL_NORMAL_LABEL, 4, 14, 0},
 {"Create Dynamic Shadow  ", 0,  (Fl_Callback*)MainWindow::cb_m_MenuItemDynamicShadow, 0, 8, FL_NORMAL_LABEL, 4, 14, 0},
 {"Test Mode", 0,  (Fl_Callback*)MainWindow::cb_m_MenuItemTest, 0, 8, FL_NORMAL_LABEL, 4, 14, 0},
 {0,0,0,0,0,0,0,0,0},
 {"About", 0,  0, 0, 64, FL_NORMAL_LABEL, 4, 14, 0},
 {"About Me           ", 0,  (Fl_Callback*)MainWindow::cb_About, 0, 0, FL_NORMAL_LABEL, 4, 14, 0},
 {0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0}
};
Fl_Menu_Item* MainWindow::m_MenuItemShowBodyLayer = MainWindow::menu_m_MenuBar + 6;
Fl_Menu_Item* MainWindow::m_MenuItemShowShadowLayer = MainWindow::menu_m_MenuBar + 7;
Fl_Menu_Item* MainWindow::m_MenuItemRectCover = MainWindow::menu_m_MenuBar + 10;
Fl_Menu_Item* MainWindow::m_MenuItemBodyFrame = MainWindow::menu_m_MenuBar + 11;
Fl_Menu_Item* MainWindow::m_MenuItemShadowFrame = MainWindow::menu_m_MenuBar + 12;
Fl_Menu_Item* MainWindow::m_MenuItemEnableEdit = MainWindow::menu_m_MenuBar + 15;
Fl_Menu_Item* MainWindow::m_MenuItemEnableAnimation = MainWindow::menu_m_MenuBar + 16;
Fl_Menu_Item* MainWindow::m_MenuItemEditCover = MainWindow::menu_m_MenuBar + 17;
Fl_Menu_Item* MainWindow::m_MenuItemEditShadow = MainWindow::menu_m_MenuBar + 18;
Fl_Menu_Item* MainWindow::m_MenuItemEditFrameAlign = MainWindow::menu_m_MenuBar + 19;
Fl_Menu_Item* MainWindow::m_MenuItemEditActionSetAlign = MainWindow::menu_m_MenuBar + 20;
Fl_Menu_Item* MainWindow::m_MenuItemDynamicShadow = MainWindow::menu_m_MenuBar + 21;
Fl_Menu_Item* MainWindow::m_MenuItemTest = MainWindow::menu_m_MenuBar + 22;

MainWindow::MainWindow() {
  { m_Window = new Fl_Double_Window(835, 474);
    m_Window->labelfont(4);
    m_Window->callback((Fl_Callback*)cb_m_Window, (void*)(this));
    { m_MenuBar = new Fl_Menu_Bar(0, 0, 1025, 30);
      m_MenuBar->labelfont(4);
      m_MenuBar->menu(menu_m_MenuBar);
    } // Fl_Menu_Bar* m_MenuBar
    { m_OperationArea = new OperationArea(0, 30, 525, 443);
      m_OperationArea->box(FL_UP_FRAME);
      m_OperationArea->color(FL_BACKGROUND_COLOR);
      m_OperationArea->selection_color(FL_BACKGROUND_COLOR);
      m_OperationArea->labeltype(FL_NORMAL_LABEL);
      m_OperationArea->labelfont(0);
      m_OperationArea->labelsize(14);
      m_OperationArea->labelcolor(FL_FOREGROUND_COLOR);
      m_OperationArea->align(Fl_Align(FL_ALIGN_CENTER));
      m_OperationArea->when(FL_WHEN_RELEASE);
    } // OperationArea* m_OperationArea
    { m_RectCoverEditGroup = new RectCoverEditGroup(541, 30, 265, 340);
      m_RectCoverEditGroup->box(FL_NO_BOX);
      m_RectCoverEditGroup->color(FL_BACKGROUND_COLOR);
      m_RectCoverEditGroup->selection_color(FL_BACKGROUND_COLOR);
      m_RectCoverEditGroup->labeltype(FL_NORMAL_LABEL);
      m_RectCoverEditGroup->labelfont(4);
      m_RectCoverEditGroup->labelsize(14);
      m_RectCoverEditGroup->labelcolor(FL_FOREGROUND_COLOR);
      m_RectCoverEditGroup->align(Fl_Align(FL_ALIGN_TOP));
      m_RectCoverEditGroup->when(FL_WHEN_RELEASE);
      m_RectCoverEditGroup->end();
    } // RectCoverEditGroup* m_RectCoverEditGroup
    { m_ShadowEditGroup = new ShadowEditGroup(541, 30, 265, 340);
      m_ShadowEditGroup->box(FL_NO_BOX);
      m_ShadowEditGroup->color(FL_BACKGROUND_COLOR);
      m_ShadowEditGroup->selection_color(FL_BACKGROUND_COLOR);
      m_ShadowEditGroup->labeltype(FL_NORMAL_LABEL);
      m_ShadowEditGroup->labelfont(4);
      m_ShadowEditGroup->labelsize(14);
      m_ShadowEditGroup->labelcolor(FL_FOREGROUND_COLOR);
      m_ShadowEditGroup->align(Fl_Align(FL_ALIGN_TOP));
      m_ShadowEditGroup->when(FL_WHEN_RELEASE);
      m_ShadowEditGroup->end();
    } // ShadowEditGroup* m_ShadowEditGroup
    { m_FrameAlignGroup = new FrameAlignGroup(541, 30, 265, 340);
      m_FrameAlignGroup->box(FL_NO_BOX);
      m_FrameAlignGroup->color(FL_BACKGROUND_COLOR);
      m_FrameAlignGroup->selection_color(FL_BACKGROUND_COLOR);
      m_FrameAlignGroup->labeltype(FL_NORMAL_LABEL);
      m_FrameAlignGroup->labelfont(4);
      m_FrameAlignGroup->labelsize(14);
      m_FrameAlignGroup->labelcolor(FL_FOREGROUND_COLOR);
      m_FrameAlignGroup->align(Fl_Align(FL_ALIGN_TOP));
      m_FrameAlignGroup->when(FL_WHEN_RELEASE);
      m_FrameAlignGroup->end();
    } // FrameAlignGroup* m_FrameAlignGroup
    { m_ActionSetAlignGroup = new ActionSetAlignGroup(541, 30, 265, 340);
      m_ActionSetAlignGroup->box(FL_NO_BOX);
      m_ActionSetAlignGroup->color(FL_BACKGROUND_COLOR);
      m_ActionSetAlignGroup->selection_color(FL_BACKGROUND_COLOR);
      m_ActionSetAlignGroup->labeltype(FL_NORMAL_LABEL);
      m_ActionSetAlignGroup->labelfont(4);
      m_ActionSetAlignGroup->labelsize(14);
      m_ActionSetAlignGroup->labelcolor(FL_FOREGROUND_COLOR);
      m_ActionSetAlignGroup->align(Fl_Align(FL_ALIGN_TOP));
      m_ActionSetAlignGroup->when(FL_WHEN_RELEASE);
      m_ActionSetAlignGroup->end();
    } // ActionSetAlignGroup* m_ActionSetAlignGroup
    { m_StatusDirectionGroup = new Fl_Group(535, 385, 290, 85);
      m_StatusDirectionGroup->labelfont(4);
      { m_ChoiceStatus = new Fl_Choice(549, 399, 265, 20);
        m_ChoiceStatus->down_box(FL_BORDER_BOX);
        m_ChoiceStatus->labelfont(4);
        m_ChoiceStatus->textfont(4);
      } // Fl_Choice* m_ChoiceStatus
      { m_ChoiceDirection = new Fl_Choice(549, 433, 265, 20);
        m_ChoiceDirection->down_box(FL_BORDER_BOX);
        m_ChoiceDirection->labelfont(4);
        m_ChoiceDirection->textfont(4);
      } // Fl_Choice* m_ChoiceDirection
      m_StatusDirectionGroup->end();
    } // Fl_Group* m_StatusDirectionGroup
    { m_DynamicShadowGroup = new DynamicShadowGroup(541, 30, 259, 350);
      m_DynamicShadowGroup->box(FL_NO_BOX);
      m_DynamicShadowGroup->color(FL_BACKGROUND_COLOR);
      m_DynamicShadowGroup->selection_color(FL_BACKGROUND_COLOR);
      m_DynamicShadowGroup->labeltype(FL_NORMAL_LABEL);
      m_DynamicShadowGroup->labelfont(4);
      m_DynamicShadowGroup->labelsize(14);
      m_DynamicShadowGroup->labelcolor(FL_FOREGROUND_COLOR);
      m_DynamicShadowGroup->align(Fl_Align(FL_ALIGN_TOP));
      m_DynamicShadowGroup->when(FL_WHEN_RELEASE);
      m_DynamicShadowGroup->end();
    } // DynamicShadowGroup* m_DynamicShadowGroup
    { m_TestGroup = new ActionSetTestGroup(541, 30, 259, 350);
      m_TestGroup->box(FL_NO_BOX);
      m_TestGroup->color(FL_BACKGROUND_COLOR);
      m_TestGroup->selection_color(FL_BACKGROUND_COLOR);
      m_TestGroup->labeltype(FL_NORMAL_LABEL);
      m_TestGroup->labelfont(4);
      m_TestGroup->labelsize(14);
      m_TestGroup->labelcolor(FL_FOREGROUND_COLOR);
      m_TestGroup->align(Fl_Align(FL_ALIGN_TOP));
      m_TestGroup->when(FL_WHEN_RELEASE);
      m_TestGroup->end();
    } // ActionSetTestGroup* m_TestGroup
    m_Window->end();
  } // Fl_Double_Window* m_Window
}

void MainWindow::ShowAll() {
  m_Window->show();
}

void MainWindow::RedrawAll() {
  if(EditCover()){
      m_RectCoverEditGroup->show();
  }else{
      m_RectCoverEditGroup->hide();
  }
  
  if(EditFrameAlign()){
      m_FrameAlignGroup->show();
  }else{
      m_FrameAlignGroup->hide();
  }
  
  if(EditShadow()){
      m_ShadowEditGroup->show();
  }else{
      m_ShadowEditGroup->hide();
  }
  
  if(EditActionSetAlign()){
      m_ActionSetAlignGroup->show();
  }else{
      m_ActionSetAlignGroup->hide();
  }
  
  // if(TestAnimation()){
  if(m_MenuItemTest->value()){
      m_StatusDirectionGroup->hide();
      //m_StatusDirectionGroup->deactivate();
      m_TestGroup->show();
  }else{
      m_StatusDirectionGroup->show();
      //m_StatusDirectionGroup->activate();
      m_TestGroup->hide();
  }
  
  if(m_MenuItemDynamicShadow->value()){
      m_DynamicShadowGroup->show();
  }else{
      m_DynamicShadowGroup->hide();
  }
  
  m_Window->redraw();
}

void MainWindow::LoadAnimationSet() {
  {
  }
}

void MainWindow::MakeCurrent() {
  {
      m_Window->make_current();
  }
}

bool MainWindow::ShowRectCover() {
  {
      return m_MenuItemRectCover->value();
  }
}

bool MainWindow::ShowBodyLayer() {
  {
      return m_MenuItemShowBodyLayer->value();
  }
}

bool MainWindow::ShowBodyFrame() {
  {
      return m_MenuItemBodyFrame->value();
  }
}

bool MainWindow::ShowShadowLayer() {
  {
      return m_MenuItemShowShadowLayer->value();
  }
}

bool MainWindow::ShowShadowFrame() {
  {
      return m_MenuItemShadowFrame->value();
  }
}

bool MainWindow::EnableEdit() {
  {
      return m_MenuItemEnableEdit->value();
  }
}

void MainWindow::EnableAnimation(bool bEnable) {
  {
      if(bEnable){
      	m_MenuItemEnableAnimation->set();    
      }else{
          m_MenuItemEnableAnimation->clear();
      }
  }
}

bool MainWindow::EditCover() {
  {
      return m_MenuItemEditCover->value();
  }
}

bool MainWindow::EditDynamicShadow() {
  {
      return m_MenuItemDynamicShadow->value();
  }
}

bool MainWindow::EditFrameAlign() {
  {
      return m_MenuItemEditFrameAlign->value();
  }
}

bool MainWindow::EditActionSetAlign() {
  {
      return m_MenuItemEditActionSetAlign->value();
  }
}

bool MainWindow::EditShadow() {
  {
      return m_MenuItemEditShadow->value();
  }
}

bool MainWindow::NeedUpdateFrame() {
  {
      return m_MenuItemEnableAnimation->value();
  }
}

int MainWindow::RectCoverCopyMethod() {
  {
      return m_RectCoverEditGroup->RectCoverCopyMethod();
  }
}

bool MainWindow::TestMode() {
  {
      // test group is open but maybe not testing now
      return m_MenuItemTest->value();
  }
}

bool MainWindow::TestAnimation() {
  {
      // now testing
      extern uint32_t g_TestAnimationCode;
      return m_MenuItemTest->value() && (g_TestAnimationCode & 0XFF000000);
  }
}

void MainWindow::TestAnimationUpdate() {
  {
      extern uint32_t g_TestAnimationCode;
      // == 1 means we finished last count
      if((g_TestAnimationCode & 0X000000FF) <= 1){
          // nIndex =  1, 2, 3, 4, 5
          uint8_t nIndex = ((g_TestAnimationCode & 0XFF000000) >> 24);
          if(nIndex == 5){
              // TODO: end of test, simply repeat
              m_TestGroup->StartTest();
              return;
          }else{
              while(nIndex + 1 != 6){
                  g_TestAnimationCode = m_TestGroup->GetTestActionSetCode(nIndex + 1);
                  uint32_t nStatus    = ((g_TestAnimationCode & 0X00FF0000) >> 16);
                  uint32_t nDirection = ((g_TestAnimationCode & 0X0000FF00) >>  8);
                  if(nStatus < 100){
                      extern AnimationSet g_AnimationSet;
                      g_AnimationSet.SetStatus(nStatus);
                      g_AnimationSet.SetDirection(nDirection);
                      return;
                  }else{
                      nIndex++;
                  }
              }
              // TODO: end of test, simply repeat
              m_TestGroup->StartTest();
              return;
          }
      }else{
          g_TestAnimationCode--;
      }
  }
}

void MainWindow::AddStatusItem() {
  {
      m_ChoiceStatus->clear();
      extern AnimationSet g_AnimationSet;
      for(int nStatus = 0; nStatus < 100; ++nStatus){
          for(int nDirection = 0; nDirection < 7; ++nDirection){
              if(g_AnimationSet.Valid(nStatus, nDirection)){
                  extern const char *g_StatusNameList[];
                  m_ChoiceStatus->add(g_StatusNameList[nStatus], 0, StatusItemCallback, (void *)nStatus, 0);
                  break;
              }
          }
      }
      if(m_ChoiceStatus->size() > 0){
          m_ChoiceStatus->value(0);
          if(m_ChoiceStatus->menu()[0].callback()){
              m_ChoiceStatus->menu()[0].do_callback(nullptr);
          }
          m_ChoiceStatus->textfont(4);
      }
      
      m_TestGroup->AddValidStatus();
      RedrawAll();
  }
}

void MainWindow::AddDirectionItem(int nStatus) {
  {
      m_ChoiceDirection->clear();
      extern AnimationSet g_AnimationSet;
      for(int nDirection = 0; nDirection < 8; ++nDirection){
          if(g_AnimationSet.Valid(nStatus, nDirection)){
              m_ChoiceDirection->add(
                      (std::string("Direction ") + std::to_string(nDirection)).c_str(),
                      0, DirectionItemCallback, (void *)nDirection, 0);
          }
      }
      if(m_ChoiceDirection->size() > 0){
          m_ChoiceDirection->value(0);
          if(m_ChoiceDirection->menu()[0].callback()){
              m_ChoiceDirection->menu()[0].do_callback(nullptr);
          }
          m_ChoiceDirection->textfont(4);
      }
      RedrawAll();
  }
}

void MainWindow::StatusItemCallback(Fl_Widget *, void *pData) {
  {
      extern AnimationSet g_AnimationSet;
      g_AnimationSet.SetStatus((int)pData);
      // printf("I am called here with: %d \n", (int)pData);
      extern MainWindow *g_MainWindow;
      g_MainWindow->AddDirectionItem((int)pData);
  }
}

void MainWindow::DirectionItemCallback(Fl_Widget *, void *pData) {
  {
      extern AnimationSet g_AnimationSet;
      g_AnimationSet.SetDirection((int)pData);
      g_AnimationSet.DSetDynamicShadowOffset(false, 0, 0);
  }
}

void MainWindow::MakeWorkingFolder() {
  {
        extern std::string g_WorkingPathName;
        if(g_WorkingPathName == "" || (g_WorkingPathName.size() > 0 && g_WorkingPathName[0] == '.')){
            time_t     stRawTime;
            struct tm *stTimeInfo;
            char       szBuffer[64];
    
            time(&stRawTime);
            stTimeInfo = localtime(&stRawTime);
            strftime(szBuffer, 64, "%Y%m%d%H%M%S", stTimeInfo);
            g_WorkingPathName = std::string("./") + szBuffer;
        }
    
        RemoveDir(g_WorkingPathName.c_str());
        MakeDir(g_WorkingPathName.c_str());
    
        std::string szTmpPath = g_WorkingPathName;
        if(szTmpPath.back() != '/'){
            szTmpPath += "/";
        }
        szTmpPath += "IMG";
        MakeDir(szTmpPath.c_str());
    }
}

void MainWindow::OperationRect(int &nX, int &nY, int &nW, int &nH) {
  {
      nX = m_OperationArea->x();
      nY = m_OperationArea->y();
      nW = m_OperationArea->w();
      nH = m_OperationArea->h();
  }
}

int MainWindow::DynamicShadowPoint() {
  {
      return m_DynamicShadowGroup->Point();
  }
}

int MainWindow::DynamicShadowMethod() {
  {
      return m_DynamicShadowGroup->Method();
  }
}

void MainWindow::DynamicShadowMethodReset() {
  {
      m_DynamicShadowGroup->Reset();
  }
}