package com.wednesdaynight.rn2c2p;

import com.facebook.react.bridge.ReadableMap;

/**
 * Created by worawat on 4/18/2017 AD.
 */

public class ReadableMapUtil {
    public static String getString(ReadableMap map, String keyName) {
        try {
            return map.getString(keyName);
        } catch (Exception e) {
        }
        return null;
    }

    public static Integer getInt(ReadableMap map, String keyName) {
        try {
            return map.getInt(keyName);
        } catch (Exception e) {
        }
        return null;
    }

    public static Boolean getBoolean(ReadableMap map, String keyName, boolean defaultValue) {
        try {
            return map.getBoolean(keyName);
        } catch (Exception e) {
        }
        return defaultValue;
    }
}
