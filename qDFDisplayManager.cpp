#include "qDFDisplayInterface.hpp"
#include <DF_Proj_Point.hpp>
#ifdef qDF_DEBUG_DISPLAY_MANAGER
#include <iostream>
#endif
#include "qDFDisplayManager.hpp"

qDFDisplayManager::~qDFDisplayManager()
{
  closeDisplays();
  enabledMap_.clear();
  interfacesMap_.clear();
}

void qDFDisplayManager::addDisplay(const QString displayName, 
                                   qDFDisplayInterface *theDisplay,
                                   bool enabled)
{
  // only add non-null displays!
  if (theDisplay)
  {
    enabledMap_[displayName] = enabled;
    interfacesMap_[displayName] = theDisplay;

#ifdef qDF_DEBUG_DISPLAY_MANAGER
    std::cerr << " added display " << displayName.toStdString();
    if (enabled)
      std::cerr << " enabled";
    else
      std::cerr << " disabled";
    std::cerr << std::endl;
#endif
  }
}

void qDFDisplayManager::enableDisplay(const QString displayName)
{
  qDFDisplayInterface *theDisplay = interfacesMap_.value(displayName);
  if (theDisplay)
  {
    // if it wasn't already enabled, initialize it
    if (!enabledMap_.value(displayName))
      theDisplay->initializeDisplay();
    enabledMap_[displayName] = true;
#ifdef qDF_DEBUG_DISPLAY_MANAGER
    std::cerr << " enabled display " << displayName.toStdString() << std::endl;
#endif
  }
}

void qDFDisplayManager::disableDisplay(const QString displayName)
{
  qDFDisplayInterface *theDisplay = interfacesMap_.value(displayName);
  if (theDisplay)
  {
    // if it wasn't already disabled, close it
    if (enabledMap_.value(displayName))
      theDisplay->closeDisplay();
    enabledMap_[displayName] = false;
#ifdef qDF_DEBUG_DISPLAY_MANAGER
    std::cerr << " disabled display " << displayName.toStdString() << std::endl;
#endif
  }
}

void qDFDisplayManager::initializeDisplays()
{
  foreach (QString theDisplayName, enabledMap_.keys())
  {
    if (enabledMap_[theDisplayName])
    {
      if (interfacesMap_[theDisplayName])
        interfacesMap_[theDisplayName]->initializeDisplay();
#ifdef qDF_DEBUG_DISPLAY_MANAGER
      std::cerr << " initialized display " << theDisplayName.toStdString() << std::endl;
#endif
    }
  }
}

void qDFDisplayManager::closeDisplays()
{
  foreach (QString theDisplayName, enabledMap_.keys())
  {
    if (enabledMap_[theDisplayName])
    {
      if (interfacesMap_[theDisplayName])
        interfacesMap_[theDisplayName]->closeDisplay();
#ifdef qDF_DEBUG_DISPLAY_MANAGER
      std::cerr << " closed display " << theDisplayName.toStdString() << std::endl;
#endif
    }
  }
}

void qDFDisplayManager::clearDisplays()
{
  foreach (QString theDisplayName, enabledMap_.keys())
  {
    if (enabledMap_[theDisplayName])
    {
      if (interfacesMap_[theDisplayName])
        interfacesMap_[theDisplayName]->clearDisplay();
#ifdef qDF_DEBUG_DISPLAY_MANAGER
      std::cerr << " cleared display " << theDisplayName.toStdString() << std::endl;
#endif
    }
  }
}

void qDFDisplayManager::displayDFReport(const qDFProjReport *theReport)
{
  foreach (QString theDisplayName, enabledMap_.keys())
  {
    if (enabledMap_[theDisplayName])
    {
      if (interfacesMap_[theDisplayName])
        interfacesMap_[theDisplayName]->displayDFReport(theReport);
#ifdef qDF_DEBUG_DISPLAY_MANAGER
      std::cerr << " display report on " << theDisplayName.toStdString() << std::endl;
#endif
    }
  }
}

void qDFDisplayManager::undisplayDFReport(const qDFProjReport *theReport)
{
  foreach (QString theDisplayName, enabledMap_.keys())
  {
    if (enabledMap_[theDisplayName])
    {
      if (interfacesMap_[theDisplayName])
        interfacesMap_[theDisplayName]->undisplayDFReport(theReport);
#ifdef qDF_DEBUG_DISPLAY_MANAGER
      std::cerr << " undisplay report on " << theDisplayName.toStdString() << std::endl;
#endif
    }
  }
}

void qDFDisplayManager::displayLSFix(DFLib::Proj::Point & LSFixPoint)
{
  foreach (QString theDisplayName, enabledMap_.keys())
  {
    if (enabledMap_[theDisplayName])
    {
      if (interfacesMap_[theDisplayName])
        interfacesMap_[theDisplayName]->displayLSFix(LSFixPoint);
#ifdef qDF_DEBUG_DISPLAY_MANAGER
      std::cerr << " display LSfix on " << theDisplayName.toStdString() << std::endl;
#endif
    }
  }
}
void qDFDisplayManager::undisplayLSFix()
{
  foreach (QString theDisplayName, enabledMap_.keys())
  {
    if (enabledMap_[theDisplayName])
    {
      if (interfacesMap_[theDisplayName])
        interfacesMap_[theDisplayName]->undisplayLSFix();
#ifdef qDF_DEBUG_DISPLAY_MANAGER
      std::cerr << " undisplay LSfix on " << theDisplayName.toStdString() << std::endl;
#endif
    }
  }
}

void qDFDisplayManager::displayFCAFix(DFLib::Proj::Point & FCAFixPoint, std::vector<double> stddevs)
{
  foreach (QString theDisplayName, enabledMap_.keys())
  {
    if (enabledMap_[theDisplayName])
    {
      if (interfacesMap_[theDisplayName])
        interfacesMap_[theDisplayName]->displayFCAFix(FCAFixPoint,stddevs);
#ifdef qDF_DEBUG_DISPLAY_MANAGER
      std::cerr << " display FCA fix on " << theDisplayName.toStdString() << std::endl;
#endif
    }
  }
}
void qDFDisplayManager::undisplayFCAFix()
{
  foreach (QString theDisplayName, enabledMap_.keys())
  {
    if (enabledMap_[theDisplayName])
    {
      if (interfacesMap_[theDisplayName])
        interfacesMap_[theDisplayName]->undisplayFCAFix();
#ifdef qDF_DEBUG_DISPLAY_MANAGER
      std::cerr << " undisplay FCA fix on " << theDisplayName.toStdString() << std::endl;
#endif
    }
  }
}
void qDFDisplayManager::displayMLFix(DFLib::Proj::Point & MLFixPoint, double am2, double bm2, double phi)
{
  foreach (QString theDisplayName, enabledMap_.keys())
  {
    if (enabledMap_[theDisplayName])
    {
      if (interfacesMap_[theDisplayName])
        interfacesMap_[theDisplayName]->displayMLFix(MLFixPoint,am2,bm2,phi);
#ifdef qDF_DEBUG_DISPLAY_MANAGER
      std::cerr << " display ML fix on " << theDisplayName.toStdString() << std::endl;
#endif

    }
  }
}
void qDFDisplayManager::undisplayMLFix()
{
  foreach (QString theDisplayName, enabledMap_.keys())
  {
    if (enabledMap_[theDisplayName])
    {
      if (interfacesMap_[theDisplayName])
        interfacesMap_[theDisplayName]->undisplayMLFix();
#ifdef qDF_DEBUG_DISPLAY_MANAGER
      std::cerr << " undisplay ML fix on " << theDisplayName.toStdString() << std::endl;
#endif

    }
  }
}
void qDFDisplayManager::displayBPEFix(DFLib::Proj::Point & BPEFixPoint, double am2, double bm2, double phi)
{
  foreach (QString theDisplayName, enabledMap_.keys())
  {
    if (enabledMap_[theDisplayName])
    {
      if (interfacesMap_[theDisplayName])
        interfacesMap_[theDisplayName]->displayBPEFix(BPEFixPoint,am2,bm2,phi);
#ifdef qDF_DEBUG_DISPLAY_MANAGER
      std::cerr << " display BPE fix on " << theDisplayName.toStdString() << std::endl;
#endif

    }
  }
}
void qDFDisplayManager::undisplayBPEFix()
{
  foreach (QString theDisplayName, enabledMap_.keys())
  {
    if (enabledMap_[theDisplayName])
    {
      if (interfacesMap_[theDisplayName])
        interfacesMap_[theDisplayName]->undisplayBPEFix();
#ifdef qDF_DEBUG_DISPLAY_MANAGER
      std::cerr << " undisplay BPE fix on " << theDisplayName.toStdString() << std::endl;
#endif
    }
  }
}
