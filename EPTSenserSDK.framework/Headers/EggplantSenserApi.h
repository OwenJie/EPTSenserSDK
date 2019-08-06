//
//  EggplantSenserApi.h
//  EggplantSenserApi
//
//  Created by Owen on 2019/5/28.
//  Copyright © 2019 eggplant. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol EggplantSenserApiDelegate <NSObject>

@optional


/**
 tv连接完成回调

 @param success 连接成功
 @param error 成功时为nil，失败时返回NSError
 */
- (void)eggplantSenserTvConected:(BOOL)success error:(NSError *)error;

/**
 tv断开连接
 */
- (void)eggplantSenserTvDisconnected;

/**
 tv进入课程
 */
- (void)eggplantSenserTvBeginDance;

/**
 tv结束课程
 */
- (void)eggplantSenserTvEndDance;

@end

@interface EggplantSenserApi : NSObject

/**
 获取SDK版本号

 @return 版本号
 */
+ (NSString *)getApiVersion;

/**
 停止采集数据
 */
+ (void)stopDance;

/**
 开始采集数据
 */
+ (void)startDance;

/**
 连接电视

 @param ipString url 格式为"ws://192.168.2.38"
 @param delegate EggplantSenserApiDelegate对象，用来接收SDK触发的消息。
 */
+ (void)connectTvWithIpString:(NSString *)ipString delegate:(id<EggplantSenserApiDelegate>)delegate;

/**
 断开电视连接
 */
+ (void)disconnectTv;

/** 设置是否在console输出sdk的log信息.
 
 @param enable 默认NO(不输出log); 设置为YES, 输出可供调试参考的log信息. 发布产品时必须设置为NO.
 */
+ (void)setLogEnabled:(BOOL)enable;

@end
