--- chrome/browser/storage_monitor/storage_monitor_chromeos.cc.orig	2014-03-27 12:23:35.947737522 -0600
+++ chrome/browser/storage_monitor/storage_monitor_chromeos.cc	2014-03-27 12:24:53.322732155 -0600
@@ -104,6 +104,7 @@
   disks::DiskMountManager::GetInstance()->AddObserver(this);
   CheckExistingMountPoints();
 
+#if defined(OS_LINUX)
   if (!media_transfer_protocol_manager_) {
     scoped_refptr<base::MessageLoopProxy> loop_proxy;
     media_transfer_protocol_manager_.reset(
@@ -113,6 +114,7 @@
   media_transfer_protocol_device_observer_.reset(
       new MediaTransferProtocolDeviceObserverLinux(
           receiver(), media_transfer_protocol_manager_.get()));
+#endif
 }
 
 void StorageMonitorCros::CheckExistingMountPoints() {
@@ -197,8 +199,10 @@
 
 void StorageMonitorCros::SetMediaTransferProtocolManagerForTest(
     device::MediaTransferProtocolManager* test_manager) {
+#if defined(OS_LINUX)
   DCHECK(!media_transfer_protocol_manager_);
   media_transfer_protocol_manager_.reset(test_manager);
+#endif
 }
 
 
@@ -276,10 +280,12 @@
                        base::Bind(NotifyUnmountResult, callback));
 }
 
+#if defined(OS_LINUX)
 device::MediaTransferProtocolManager*
 StorageMonitorCros::media_transfer_protocol_manager() {
   return media_transfer_protocol_manager_.get();
 }
+#endif
 
 void StorageMonitorCros::AddMountedPath(
     const disks::DiskMountManager::MountPointInfo& mount_info, bool has_dcim) {
