--- ./tools/gyp/pylib/gyp/generator/make.py.orig	2014-03-04 03:18:32.000000000 +0100
+++ ./tools/gyp/pylib/gyp/generator/make.py	2014-03-07 14:10:36.000000000 +0100
@@ -87,7 +87,7 @@
   else:
     operating_system = flavor
     if flavor == 'android':
-      operating_system = 'linux'  # Keep this legacy behavior for now.
+      operating_system = 'freebsd'  # Keep this legacy behavior for now.
     default_variables.setdefault('OS', operating_system)
     default_variables.setdefault('SHARED_LIB_SUFFIX', '.so')
     default_variables.setdefault('SHARED_LIB_DIR','$(builddir)/lib.$(TOOLSET)')
@@ -281,7 +281,7 @@
 CFLAGS.target ?= $(CFLAGS)
 CXX.target ?= %(CXX.target)s
 CXXFLAGS.target ?= $(CXXFLAGS)
-LINK.target ?= %(LINK.target)s
+LINK.target ?= %(CXX.target)s
 LDFLAGS.target ?= $(LDFLAGS)
 AR.target ?= $(AR)
 
@@ -298,13 +298,13 @@
 
 # TODO(evan): move all cross-compilation logic to gyp-time so we don't need
 # to replicate this environment fallback in make as well.
-CC.host ?= %(CC.host)s
-CFLAGS.host ?=
-CXX.host ?= %(CXX.host)s
-CXXFLAGS.host ?=
-LINK.host ?= %(LINK.host)s
-LDFLAGS.host ?=
-AR.host ?= %(AR.host)s
+CC.host ?= $(CC)
+CFLAGS.host ?= $(CFLAGS)
+CXX.host ?= $(CXX)
+CXXFLAGS.host ?= $(CXXFLAGS)
+LINK.host ?= $(CXX)
+LDFLAGS.host ?= $(LDFLAGS)
+AR.host ?= $(AR)
 
 # Define a dir function that can handle spaces.
 # http://www.gnu.org/software/make/manual/make.html#Syntax-of-Functions
@@ -1793,7 +1793,7 @@
       return modules
 
     # Retrieve the default value of 'SHARED_LIB_SUFFIX'
-    params = {'flavor': 'linux'}
+    params = {'flavor': 'freebsd'}
     default_variables = {}
     CalculateVariables(default_variables, params)
 
