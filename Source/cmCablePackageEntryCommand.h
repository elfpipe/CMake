/*=========================================================================

  Program:   Insight Segmentation & Registration Toolkit
  Module:    $RCSfile$
  Language:  C++
  Date:      $Date$
  Version:   $Revision$

Copyright (c) 2001 Insight Consortium
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

 * Redistributions of source code must retain the above copyright notice,
   this list of conditions and the following disclaimer.

 * Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

 * The name of the Insight Consortium, nor the names of any consortium members,
   nor of any contributors, may be used to endorse or promote products derived
   from this software without specific prior written permission.

  * Modified source versions must be plainly marked as such, and must not be
    misrepresented as being the original software.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDER AND CONTRIBUTORS ``AS IS''
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

=========================================================================*/
#ifndef cmCablePackageEntryCommand_h
#define cmCablePackageEntryCommand_h

#include "cmStandardIncludes.h"
#include "cmCableCommand.h"

/** \class cmCablePackageEntryCommand
 * \brief Superclass to all CABLE Package entry generation commands.
 *
 * cmCablePackageEntryCommand implements the Invoke method of a cmCommand
 * to save the arguments as a vector of entries to a CABLE Package.  The
 * Invoke then calls the virtual WriteConfiguration() so that the subclass
 * can generate the configuration code for its particular type of Package
 * entry.
 */
class cmCablePackageEntryCommand : public cmCableCommand
{
public:
  cmCablePackageEntryCommand() {}
  virtual ~cmCablePackageEntryCommand() {}
  
  /**
   * This is called when the command is first encountered in
   * the CMakeLists.txt file.
   */
  virtual bool Invoke(std::vector<std::string>& args);  

  cmTypeMacro(cmCablePackageEntryCommand, cmCableCommand);

  virtual void WriteConfiguration() const =0;
protected:
  typedef std::vector<std::string>  Entries;
  
  /**
   * The package entries.
   */
  Entries m_Entries;
};



#endif
