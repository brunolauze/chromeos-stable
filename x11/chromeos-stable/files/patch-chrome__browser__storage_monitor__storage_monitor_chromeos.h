--- chrome/browser/storage_monitor/storage_monitor_chromeos.h.orig	2014-03-27 12:23:05.308740512 -0600
+++ chrome/browser/storage_monitor/storage_monitor_chromeos.h	2014-03-27 12:23:32.743737328 -0600
@@ -62,8 +62,10 @@
   virtual void EjectDevice(
       const std::string& device_id,
       base::Callback<void(EjectStatus)> callback) OVERRIDE;
+#if defined(OS_LINUX)
   virtual device::MediaTransferProtocolManager*
       media_transfer_protocol_manager() OVERRIDE;
+#endif
 
  private:
   // Mapping of mount path to removable mass storage info.
