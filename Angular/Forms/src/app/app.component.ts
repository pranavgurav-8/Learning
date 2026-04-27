import { NgFor } from '@angular/common';
import { Component, NgModule } from '@angular/core';
import { NgForm } from '@angular/forms';
import { RouterOutlet } from '@angular/router';

@Component({
  selector: 'app-root',
  imports: [RouterOutlet,NgFor,NgModule, NgForm],
  standalone: true,
  templateUrl: './app.component.html',
  styleUrl: './app.component.css'
})
export class AppComponent {
  title = 'Forms';
  topics = ['Angular', 'React', 'Vue', 'Svelte', 'Ember', 'Backbone', 'jQuery', 'Bootstrap', 'Tailwind CSS', 'Material Design'];
}
