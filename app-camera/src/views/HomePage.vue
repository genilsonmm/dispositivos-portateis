<template>
  <ion-page>
    <ion-header :translucent="true">
      <ion-toolbar>
        <ion-title>Blank</ion-title>
      </ion-toolbar>
    </ion-header>

    <ion-content :fullscreen="true">
      <ion-header collapse="condense">
        <ion-toolbar>
          <ion-title size="large">Blank</ion-title>
        </ion-toolbar>
      </ion-header>
      
      <img :src="imgUrl" alt="foto" />
      <button @click="takePhoto">Foto</button>

    </ion-content>
  </ion-page>
</template>

<script setup lang="ts">
import { IonContent, 
  IonHeader, 
  IonPage, 
  IonTitle, 
  IonToolbar,
 } from '@ionic/vue';

import {Camera, CameraResultType} from "@capacitor/camera";
import { ref } from "vue"

const imgUrl = ref()

const takePhoto = async () => {
  const image = await Camera.getPhoto({
    resultType: CameraResultType.Uri,
    quality: 100,
    allowEditing: true,
    saveToGallery: true
  })

  imgUrl.value = image.webPath
}

</script>

<style scoped>
#container {
  text-align: center;
  
  position: absolute;
  left: 0;
  right: 0;
  top: 50%;
  transform: translateY(-50%);
}

#container strong {
  font-size: 20px;
  line-height: 26px;
}

#container p {
  font-size: 16px;
  line-height: 22px;
  
  color: #8c8c8c;
  
  margin: 0;
}

#container a {
  text-decoration: none;
}
</style>
