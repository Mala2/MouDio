//
//  FscBleCentralApi.h
//  FscBleCentral
//
//  Created by Feasycom on 2017/12/26.
//  Copyright © 2017 Feasycom. All rights reserved.
//

typedef enum {
    BLEMODULE = 0,  // ble type
    BEACONMODULE    // beacon type
} MODULETYPE;

// Release Date: 2019-9-29

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
@class FWPeripheralWrapper;
@class BeaconBean;

@interface FscBleCentralApi : NSObject
/**
 *  Module type
 */
@property (nonatomic, assign) MODULETYPE moduleType;
/**
 *  Last connected peripheral    连接的设备
 */
@property (nonatomic, strong) CBPeripheral *peripheral;
/**
 *  BroadCast info   广播信息
 */
@property (nonatomic, strong) NSArray <FWPeripheralWrapper *>*broadCastInfoArray;
/**
 *  Beacon info    beacon信息
 */
@property (nonatomic, strong) NSArray *beaconInfoArray;
/**
 *  Peripherals info 外围设备信息
 */
@property (nonatomic, strong) NSArray *peripheralsInfoArray;

/**
 *  centralManager
 */
- (CBCentralManager *)centralManager;

//-----------------------------------  callbacks  -------------------------------------//
/**
 * peripheral enabled callback   蓝牙是否打开的回调
 */
- (void)isBtEnabled:(void (^)(CBCentralManager *central))block;
/**
 * peripheral found callback  发现外围加调
 */
- (void)blePeripheralFound:(void (^)(CBCentralManager *central,CBPeripheral *peripheral,NSDictionary *advertisementData, NSNumber *RSSI))block;
/**
 * peripheral connected callback 设备已经连接的回调
 */
- (void)blePeripheralConnected:(void (^)(CBCentralManager *central,CBPeripheral *peripheral))block;
/**
 *  discover services   发现服务
 */
- (void)servicesFound:(void (^)(NSArray <CBService *>*services,NSError *error))block;
/**
 *  peripheral disconnected callback 外围断开连接的回调
 */
- (void)blePeripheralDisonnected:(void (^)(CBCentralManager *central,CBPeripheral *peripheral,NSError *error))block;
/**
 * write value with response callback 数据发送带response的回调
 */
- (void)sendCompleted:(void (^)(CBCharacteristic *characteristic,NSData *data,NSError *error))block;
/**
 * received packet callback 收到的回调
 */
- (void)packetReceived:(void (^)(CBPeripheral *peripheral,NSData *data,NSError *error))block;
/**
 * response for characteristic value read  特征值读取到数据的回调
 */
- (void)readResponse:(void (^)(CBCharacteristic * characteristic))block;
/**
 * response for send AT commands 发送空中指令的回调
 */
- (void)fscAtResponse:(void (^)(NSString *type,int status))block;
/**
 * update progress callbacks 升级进度回调
 */
- (void)otaProgressUpdate:(void (^)(CGFloat percentage,int status))block;
/**
 * device info callbacks 查询设备信息的回调
 */
- (void)deviceInfo:(void (^)(NSArray *infoArray))block;

/**
 * write ready 已经准备好写数据
 */
- (void)peripheralWriteDidReady:(void (^)(void))block;

/**
 * single_one
 */
+ (instancetype)shareFscBleCentralApi;
/**
 * single_two
 */
+ (instancetype)defaultFscBleCentralApi;
/**
 * SDK version 版本好
 */
+ (NSString *)SDKVersion;
/**
 * start scan peripherals  开始扫瞄
 */
- (void)startScan;
/**
 * start scan peripherals with UUIDs 扫描带有特定服务的设备
 */
- (void)startScanWithServiceUUIDs:(NSArray<CBUUID *> *)UUIDs allowDuplicates:(BOOL)allowDuplicates;
/**
 * stop scan peripherals  停止扫描
 */
- (void)stopScan;
/**
 * connect peripheral(BLE) 连接设备
 */
- (void)connect:(CBPeripheral *)peripheral;

/**
 * connect peripheral(beacon)  连接外围
 */
- (void)connect:(FWPeripheralWrapper *)peripheralWrapper withPin:(NSString *)pin;
/**
 * disconnect peripheral 断开
 */
- (void)disconnect;
/**
 * retrieve peripherals 根据uuid取回设备
 */
- (NSArray<CBPeripheral *> *)retrievePeripheralsWithIdentifiers:(NSArray<NSUUID *> *)identifiers;
/**
 * send data to peripheral, response is flow control 发送数据
 */
- (void)send:(NSData *)data withResponse:(BOOL)response withSendStatusBlock:(void (^)(NSData *data))block;
/**
 * send data to peripheral, response is flow control(sync) 同步发送数据
 */
- (void)syncSend:(NSData *)data withResponse:(BOOL)response;
/**
 * stop send data to peripheral and reset sending status 停止发送数据
 */
- (void)stopSend;
/**
 * if YES, start the facp, the default is NO facp 1.0是否开启
 */
- (void)facpControl:(BOOL)control;

/**
 * set characteristic 特征值开启通知
 */
- (void)setCharacteristic:(NSString *)serviceUUID withCharacteristicUUID:(NSString *)characteristicUUID withNotify:(BOOL)notify infoBlock:(void (^)(BOOL result))block;
/**
 * read characteristic value 读取特征值的数据
 */
- (void)read:(CBCharacteristic *)characteristic;
/**
 * set send interval(ms) 设置发送间隔，单位毫秒
 */
- (void)setSendInterval:(NSInteger)interval;
/**
 * clear buffer cache 清除缓存
 */
- (void)clearCache;
/**
 * set mtu 设置最大传输单元
 */
- (void)setAttMtu:(NSInteger)mtu;
/**
 * restore mtu 恢复最大传输单元
 */
- (void)restoreMtu;
/**
 * send AT commands 发送空中指令
 */
- (void)sendFscAtCommands:(NSArray *)commandArray;
/**
 * load file and check file information 检查文件信息
 */
- (NSDictionary *)checkDfuFile:(NSString *)dfuFileName;
/**
 * upgrade and restore default settings 开始空中升级
 */
- (void)startOTA:(NSString *)dfuFileName withRestoreDefaultSettings:(BOOL)restore;

//----------------------------------  beacon  ------------------------------------------//
/**
 * get device info, also see "deviceInfo:" 获取设备信息
 */
- (void)startGetDeviceInfo;
/**
 * set device name  设备名称
 */
- (void)setDeviceName:(NSString *)deviceName;
/**
 * set feasyBeacon pin 设置Beacon的pin码
 */
- (void)setFscPin:(NSString *)pin;
/**
 * set broadcast interval 设置广播间隔
 */
- (void)setBroadcastInterval:(NSString *)interval;
/**
 * set tx power 设置TxPower值
 */
- (void)setTxPower:(NSString *)txPower;
/**
 * set connectable or not 设置BWMODE
 */
- (void)setConnectable:(BOOL)connectable;
/**
 * add beacon broadcast 增加beacon广播
 */
- (void)addBeaconInfo:(BeaconBean *)beaconBean;
/**
 * delete beacon broadcast of index 删除beacon广播
 */
- (void)deleteBeaconInfo:(uint32_t)index;
/**
 * update beacon info of index 修改广播
 */
- (void)updateBeaconInfo:(BeaconBean *)beaconBean withIndex:(uint32_t)index withPosition:(uint32_t)position;
/**
 * get beacon info of index 查询单条beacon信息
 */
- (BeaconBean *)getBeaconInfo:(uint32_t)index;

// 保存参数设置
- (void)saveBeaconInfo;


@end

