/*****************************************************************************
 * utils.h
 *****************************************************************************
 * Copyright © 2012 VLC authors and VideoLAN
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/

#ifndef LIBVLCJNI_UTILS_H
#define LIBVLCJNI_UTILS_H

#include <vlc/vlc.h>
#include <vlc/libvlc_media.h>
#include <vlc/libvlc_media_list.h>

struct fields {
    jint SDK_INT;
    struct {
        jclass clazz;
    } IllegalStateException;
    struct {
        jclass clazz;
    } IllegalArgumentException;
    struct {
        jclass clazz;
    } String;
    struct {
        jclass clazz;
        jfieldID descriptorID;
    } FileDescriptor;
    struct {
        jclass clazz;
        jmethodID onNativeCrashID;
    } LibVLC;
    struct {
        jclass clazz;
        jfieldID mInstanceID;
        jmethodID dispatchEventFromNativeID;
        jmethodID getWeakReferenceID;
        jmethodID dispatchEventFromWeakNativeID;
    } VLCObject;
    struct {
        struct {
            jclass clazz;
        } Track;

        jclass clazz;
        jmethodID createAudioTrackFromNativeID;
        jmethodID createVideoTrackFromNativeID;
        jmethodID createSubtitleTrackFromNativeID;
    } Media;
};

extern struct fields fields;

jint getInt(JNIEnv *env, jobject thiz, const char* field);

void setInt(JNIEnv *env, jobject item, const char* field, jint value);

jlong getLong(JNIEnv *env, jobject thiz, const char* field);

void setLong(JNIEnv *env, jobject item, const char* field, jlong value);

void setFloat(JNIEnv *env, jobject item, const char* field, jfloat value);

void setString(JNIEnv *env, jobject item, const char* field, const char* text);

void arrayListGetIDs(JNIEnv *env, jclass* p_class, jmethodID* p_add, jmethodID* p_remove);

void arrayListStringAdd(JNIEnv *env, jclass class, jmethodID methodID, jobject arrayList, const char* str);

jobject getEventHandlerReference(JNIEnv *env, jobject thiz, jobject eventHandler);

#endif // LIBVLCJNI_UTILS_H
