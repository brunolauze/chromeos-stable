--- content/content_common.gypi.orig	2014-03-14 21:21:14.000000000 -0600
+++ content/content_common.gypi	2014-03-27 14:05:34.691332142 -0600
@@ -482,6 +482,20 @@
         'content.gyp:common_aidl',
       ],
     }],
+    ['os_bsd==1', {
+      'sources!': [
+        'common/sandbox_linux/sandbox_linux.cc',
+        'common/sandbox_linux/sandbox_linux.h',
+        'common/sandbox_linux/sandbox_init_linux.cc',
+        'common/sandbox_linux/sandbox_seccomp_bpf_linux.cc',
+        'common/sandbox_linux/sandbox_seccomp_bpf_linux.h',
+        'common/sandbox_linux/bpf_cros_arm_gpu_policy_linux.cc',
+        'common/sandbox_linux/bpf_gpu_policy_linux.cc',
+        'common/sandbox_linux/bpf_ppapi_policy_linux.cc',
+        'common/sandbox_linux/bpf_renderer_policy_linux.cc',
+        'common/sandbox_linux/sandbox_bpf_base_policy_linux.cc',
+      ],
+    }],
     ['toolkit_uses_gtk == 1', {
       'dependencies': [
         '../build/linux/system.gyp:gtk',
