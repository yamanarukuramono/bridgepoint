.//=====================================================================
.//
.// File:      $RCSfile: create_selection_dialog_action.inc,v $
.// Version:   $Revision: 1.10 $
.// Modified:  $Date: 2013/01/10 22:54:06 $
.//
.// (c) Copyright 2008-2014 by Mentor Graphics Corp. All rights reserved.
.//
.//=====================================================================
.// Licensed under the Apache License, Version 2.0 (the "License"); you may not
.// use this file except in compliance with the License.  You may obtain a copy
.// of the License at
.//
.//      http://www.apache.org/licenses/LICENSE-2.0
.//
.// Unless required by applicable law or agreed to in writing, software
.// distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
.// WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.   See the
.// License for the specific language governing permissions and limitations under
.// the License.
.//=====================================================================
.//
.include "${arc_dir}/chooser_elements_provider.inc"
.//
.function create_selection_dialog_action
  .param string path
  .param inst_ref cme
  .//
  .invoke result = get_action_class_name(cme)
  .assign action_name = "${result.body}"
  .assign attr_result = action_name  
  .select one class related by cme->O_OBJ[R2000]
  .invoke cn = get_class_name(class)
  .assign has_wizard = false
  .invoke fn = get_func_name(cme)
package org.xtuml.bp.core.ui.actions;
//======================================================================
//
// File: ${path}/${action_name}.java
//
// WARNING:      Do not edit this generated file
// Generated by: ${info.arch_file_name}
// Version:      $$Revision: 1.10 $$
//
// (c) Copyright 2005-2014 by Mentor Graphics Corp.  All rights reserved.
//
//======================================================================
//
// This class is the main BridgePoint entry point for the action that
// opens a selection dialog for ${cme.Label}s.
//

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;
import java.util.List;

import org.eclipse.core.resources.IProject;
import org.eclipse.core.resources.ProjectScope;
import org.eclipse.jface.action.IAction;
import org.eclipse.jface.dialogs.MessageDialog;
import org.eclipse.jface.viewers.ISelection;
import org.eclipse.jface.viewers.IStructuredSelection;
import org.eclipse.jface.window.Window;
import org.eclipse.ui.IActionDelegate;
import org.eclipse.ui.IObjectActionDelegate;
import org.eclipse.ui.IWorkbenchPart;
import org.eclipse.ui.PlatformUI;

import org.xtuml.bp.core.*;
import org.xtuml.bp.core.common.*;
import org.xtuml.bp.core.ui.*;
import org.xtuml.bp.core.util.*;
import org.xtuml.bp.core.ui.dialogs.*;
import org.osgi.service.prefs.*;
import org.xtuml.bp.core.ui.preferences.*;

public class ${action_name} implements IObjectActionDelegate {

  /**
   * Constructor for ${action_name}.
   */
  public ${action_name}() {
    super();
  }
  /**
   * @see IObjectActionDelegate#setActivePart(IAction, IWorkbenchPart)
   */
  public void setActivePart(IAction action, IWorkbenchPart targetPart) {
    // The part is mainly needed to locate the selection provider, and
    // we cache our selection in core so no action is needed here.
  }
  /**
   * @see IActionDelegate#run(IAction)
   */
  public void run(IAction action) {
    IStructuredSelection structuredSelection = Selection.getInstance().getStructuredSelection();
  .// invoke the nominated function generated from the client model
    ${fn.body}(structuredSelection);
 }
  /**
   * @see IActionDelegate#selectionChanged(IAction, ISelection)
   */
  public void selectionChanged(IAction action, ISelection selection) {
		// do nothing
  }
  public static void ${fn.body}(IStructuredSelection selection) {
      .select any function from instances of S_SYNC where ("${selected.Name}" == "${fn.body}")
      .if (not_empty function)
        .invoke result = function_body(function)
${result.body}
      .else
        .print "ERROR: No function found for context menu entry: $Cr{cme.Label}"
      .end if
  }
  .invoke result = generate_chooser_element_function(function)
${result.body}
} // end ${action_name}
.end function
.//
.//
.//
